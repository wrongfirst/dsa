#!/usr/bin/env node
/**
 * Scaffold starter template.<ext> files for DSA exercises from canonical-data.json.
 * 
 * Usage:
 *   npx tsx scripts/gen-templates.ts --exercise=<id> [--lang=<id>] [--force]
 *   npx tsx scripts/gen-templates.ts --all [--lang=<id>] [--force]
 */

import fs from 'node:fs';
import path from 'node:path';
import { fileURLToPath } from 'node:url';

const __filename = fileURLToPath(import.meta.url);
const __dirname = path.dirname(__filename);
const ROOT_DIR = path.resolve(__dirname, '..');
const EXERCISES_DIR = path.join(ROOT_DIR, 'src', 'exercises');
const LANGUAGES_DIR = path.join(ROOT_DIR, 'src', 'languages');

interface CliArgs {
  exercise?: string;
  all?: boolean;
  lang?: string;
  force?: boolean;
}

function parseArgs(): CliArgs {
  const args = process.argv.slice(2);
  const result: CliArgs = {};

  for (const arg of args) {
    if (arg === '--all') {
      result.all = true;
    } else if (arg.startsWith('--exercise=')) {
      result.exercise = arg.split('=')[1];
    } else if (arg.startsWith('--lang=')) {
      result.lang = arg.split('=')[1];
    } else if (arg === '--force' || arg === '-f') {
      result.force = true;
    }
  }

  return result;
}

interface LanguageModule {
  id: string;
  extension: string;
  buildTemplateCode?: (meta: any) => string;
}

function getActiveLanguages(): string[] {
  const siteTomlPath = path.join(ROOT_DIR, 'site.toml');
  if (!fs.existsSync(siteTomlPath)) {
    throw new Error(`site.toml not found at ${siteTomlPath}`);
  }

  const content = fs.readFileSync(siteTomlPath, 'utf-8');

  const langsMatch = content.match(/languages\s*=\s*\[(.*?)\]/s);
  if (langsMatch) {
    const list = langsMatch[1]
      .split(',')
      .map(s => s.trim().replace(/['"]/g, ''))
      .filter(Boolean);
    if (list.length > 0) return list;
  }

  const defaultMatch = content.match(/default_language\s*=\s*['"](.*?)['"]/);
  if (defaultMatch && defaultMatch[1].trim()) {
    return [defaultMatch[1].trim()];
  }

  throw new Error(`Could not determine active languages or default_language from ${siteTomlPath}`);
}

async function discoverLanguages(targetLang?: string): Promise<LanguageModule[]> {
  const activeLangs = targetLang ? [targetLang] : getActiveLanguages();
  const modules: LanguageModule[] = [];

  for (const id of activeLangs) {

    const runnerPath = path.join(LANGUAGES_DIR, id, 'test-runner.ts');
    const metadataPath = path.join(LANGUAGES_DIR, id, 'metadata.ts');

    if (!fs.existsSync(runnerPath) || !fs.existsSync(metadataPath)) {
      continue;
    }

    try {
      const metaModule = await import(`file://${metadataPath}`);
      const metadata = metaModule.metadata || metaModule.default;
      const extension = metadata?.extension;

      if (!extension) continue;

      const runnerModule = await import(`file://${runnerPath}`);
      const buildTemplateCode = runnerModule.buildTemplateCode || runnerModule.default?.buildTemplateCode;

      modules.push({
        id,
        extension,
        buildTemplateCode
      });
    } catch (err) {
      console.warn(`[WARN] Could not load language module for '${id}':`, err);
    }
  }

  return modules;
}

async function run() {
  const args = parseArgs();

  if (!args.exercise && !args.all) {
    console.error('Usage:');
    console.error('  npx tsx scripts/gen-templates.ts --exercise=<id> [--lang=<id>] [--force]');
    console.error('  npx tsx scripts/gen-templates.ts --all [--lang=<id>] [--force]');
    process.exit(1);
  }

  const languages = await discoverLanguages(args.lang);
  if (languages.length === 0) {
    console.error(`No language modules with test-runner.ts found${args.lang ? ` matching '${args.lang}'` : ''}.`);
    process.exit(1);
  }

  const exerciseIds = args.all
    ? fs.readdirSync(EXERCISES_DIR, { withFileTypes: true })
        .filter(d => d.isDirectory() && fs.existsSync(path.join(EXERCISES_DIR, d.name, 'canonical-data.json')))
        .map(d => d.name)
    : [args.exercise!];

  console.log(`\nScaffolding templates for ${exerciseIds.length} exercise(s) across ${languages.length} language(s)...\n`);

  let createdCount = 0;
  let skippedCount = 0;
  let missingGeneratorCount = 0;

  for (const exId of exerciseIds) {
    const exDir = path.join(EXERCISES_DIR, exId);
    const canonicalPath = path.join(exDir, 'canonical-data.json');

    if (!fs.existsSync(canonicalPath)) {
      console.warn(`[SKIP] Missing canonical-data.json for exercise: ${exId}`);
      continue;
    }

    let canonicalData: any;
    try {
      canonicalData = JSON.parse(fs.readFileSync(canonicalPath, 'utf-8'));
    } catch (err: any) {
      console.error(`[ERROR] Invalid JSON in ${canonicalPath}:`, err?.message);
      continue;
    }

    for (const lang of languages) {
      const targetDir = path.join(exDir, lang.id);
      const targetFile = path.join(targetDir, `template${lang.extension}`);

      if (fs.existsSync(targetFile) && !args.force) {
        skippedCount++;
        continue;
      }

      if (!lang.buildTemplateCode) {
        missingGeneratorCount++;
        console.warn(`[NO-GEN] ${lang.id}: test-runner.ts does not export buildTemplateCode()`);
        continue;
      }

      try {
        const templateCode = lang.buildTemplateCode(canonicalData);
        if (!templateCode || !templateCode.trim()) {
          console.warn(`[EMPTY] ${lang.id}: buildTemplateCode returned empty string for ${exId}`);
          continue;
        }

        if (!fs.existsSync(targetDir)) {
          fs.mkdirSync(targetDir, { recursive: true });
        }

        fs.writeFileSync(targetFile, templateCode.trimEnd() + '\n', 'utf-8');
        console.log(`[CREATED] ${path.relative(ROOT_DIR, targetFile)}`);
        createdCount++;
      } catch (err: any) {
        console.error(`[FAIL] ${lang.id} template generation failed for ${exId}:`, err?.message || err);
      }
    }
  }

  console.log(`\nTemplate Scaffolding Summary:`);
  console.log(`  - Created: ${createdCount}`);
  console.log(`  - Skipped (already exists): ${skippedCount}`);
  if (missingGeneratorCount > 0) {
    console.log(`  - Missing buildTemplateCode(): ${missingGeneratorCount}`);
  }
}

run().catch((err) => {
  console.error('Fatal error running template generator:', err);
  process.exit(1);
});
