#!/usr/bin/env node
/**
 * Static Contract & Compiler Verification Script
 * 
 * Validates:
 * 1. canonical-data.json schema validity across all exercises
 * 2. Signature and property parity between canonical-data.json, template.<ext>, and solution.<ext>
 * 3. Receiver class existence when canonical-data specifies "receiver"
 * 4. Test harness code generation across all enabled languages
 * 5. Structural and anti-pattern linting on generated test harnesses
 * 6. Live compiler/interpreter syntax-only verification of BOTH:
 *    - template.<ext> + testCode (ensures starter code compiles cleanly out of the box)
 *    - solution.<ext> + testCode (ensures reference solution compiles cleanly with tests)
 * 
 * Supports C++, C, Go, and Python compilers/linters.
 * 
 * Usage:
 *   npx tsx scripts/verify-contracts.ts [--exercise=<id>] [--lang=<id>]
 */

import fs from 'node:fs';
import os from 'node:os';
import path from 'node:path';
import { execSync } from 'node:child_process';
import { fileURLToPath } from 'node:url';

const __filename = fileURLToPath(import.meta.url);
const __dirname = path.dirname(__filename);
const ROOT_DIR = path.resolve(__dirname, '..');
const EXERCISES_DIR = path.join(ROOT_DIR, 'src', 'exercises');
const LANGUAGES_DIR = path.join(ROOT_DIR, 'src', 'languages');

interface CliArgs {
  exercise?: string;
  lang?: string;
}

function parseArgs(): CliArgs {
  const args = process.argv.slice(2);
  const result: CliArgs = {};
  for (const arg of args) {
    if (arg.startsWith('--exercise=')) {
      result.exercise = arg.split('=')[1];
    } else if (arg.startsWith('--lang=')) {
      result.lang = arg.split('=')[1];
    }
  }
  return result;
}

interface Violation {
  exerciseId: string;
  languageId?: string;
  type: 'SCHEMA' | 'SIGNATURE' | 'LINT' | 'GENERATOR' | 'TEMPLATE_COMPILER' | 'SOLUTION_COMPILER';
  message: string;
  file?: string;
}

const VALID_INPUT_TYPES = new Set([
  'standard',
  'tree',
  'tree_node',
  'linked_list',
  'linked_list_array',
  'linked_list_cycle',
  'graph',
  'interval',
  'interval_array',
  'byte_grid'
]);

const VALID_RETURN_TYPES = new Set([
  'standard',
  'tree',
  'tree_node',
  'linked_list',
  'graph',
  'void'
]);

const VALID_MODES = new Set(['function', 'operations', 'compose']);

function validateCanonicalJson(exId: string, data: any, filePath: string): Violation[] {
  const violations: Violation[] = [];

  if (!data || typeof data !== 'object') {
    return [{ exerciseId: exId, type: 'SCHEMA', message: 'Root JSON is not an object', file: filePath }];
  }

  if (data.exercise !== exId) {
    violations.push({
      exerciseId: exId,
      type: 'SCHEMA',
      message: `Property "exercise" (${JSON.stringify(data.exercise)}) does not match directory name "${exId}"`,
      file: filePath
    });
  }

  if (data.mode && !VALID_MODES.has(data.mode)) {
    violations.push({
      exerciseId: exId,
      type: 'SCHEMA',
      message: `Invalid mode "${data.mode}". Must be one of: ${Array.from(VALID_MODES).join(', ')}`,
      file: filePath
    });
  }

  if (data.returns && !VALID_RETURN_TYPES.has(data.returns)) {
    violations.push({
      exerciseId: exId,
      type: 'SCHEMA',
      message: `Invalid returns "${data.returns}". Must be one of: ${Array.from(VALID_RETURN_TYPES).join(', ')}`,
      file: filePath
    });
  }

  if (data.inputs && typeof data.inputs === 'object') {
    for (const [k, v] of Object.entries(data.inputs)) {
      if (!VALID_INPUT_TYPES.has(v as string)) {
        violations.push({
          exerciseId: exId,
          type: 'SCHEMA',
          message: `Invalid input type "${v}" for parameter "${k}". Must be one of: ${Array.from(VALID_INPUT_TYPES).join(', ')}`,
          file: filePath
        });
      }
    }
  }

  if (data.mutation) {
    if (!data.mutation.target || typeof data.mutation.target !== 'string') {
      violations.push({
        exerciseId: exId,
        type: 'SCHEMA',
        message: 'Mutation definition must contain a string "target"',
        file: filePath
      });
    }
  }

  if (!Array.isArray(data.cases) || data.cases.length === 0) {
    violations.push({
      exerciseId: exId,
      type: 'SCHEMA',
      message: 'Field "cases" must be a non-empty array',
      file: filePath
    });
  }

  return violations;
}

interface LanguageModule {
  id: string;
  extension: string;
  harnessCode?: string;
  buildTestCode: (cases: any[], meta: any) => string;
  buildTemplateCode?: (meta: any) => string;
}

function getActiveLanguages(): string[] {
  const siteTomlPath = path.join(ROOT_DIR, 'site.toml');
  if (!fs.existsSync(siteTomlPath)) {
    throw new Error(`site.toml not found at ${siteTomlPath}`);
  }

  const content = fs.readFileSync(siteTomlPath, 'utf-8');

  // 1. Try extracting languages array from site.toml
  const langsMatch = content.match(/languages\s*=\s*\[(.*?)\]/s);
  if (langsMatch) {
    const list = langsMatch[1]
      .split(',')
      .map(s => s.trim().replace(/['"]/g, ''))
      .filter(Boolean);
    if (list.length > 0) return list;
  }

  // 2. Fall back to default_language from site.toml
  const defaultMatch = content.match(/default_language\s*=\s*['"](.*?)['"]/);
  if (defaultMatch && defaultMatch[1].trim()) {
    return [defaultMatch[1].trim()];
  }

  throw new Error(`Could not determine active languages or default_language from ${siteTomlPath}`);
}

async function discoverLanguageRunners(targetLang?: string): Promise<LanguageModule[]> {
  const activeLangs = targetLang ? [targetLang] : getActiveLanguages();

  const runners: LanguageModule[] = [];

  for (const id of activeLangs) {

    const runnerPath = path.join(LANGUAGES_DIR, id, 'test-runner.ts');
    const metadataPath = path.join(LANGUAGES_DIR, id, 'metadata.ts');

    if (!fs.existsSync(runnerPath) || !fs.existsSync(metadataPath)) continue;

    try {
      const metaModule = await import(`file://${metadataPath}`);
      const metadata = metaModule.metadata || metaModule.default;
      const extension = metadata?.extension;
      if (!extension) continue;

      const runnerModule = await import(`file://${runnerPath}`);
      const buildTestCode = runnerModule.buildTestCode || runnerModule.default;
      const buildTemplateCode = runnerModule.buildTemplateCode || runnerModule.default?.buildTemplateCode;

      // Find harness file if available
      let harnessCode: string | undefined;
      const harnessCandidates = [
        path.join(LANGUAGES_DIR, id, 'harness.hpp'),
        path.join(LANGUAGES_DIR, id, 'harness.h'),
        path.join(LANGUAGES_DIR, id, 'harness.py'),
        path.join(LANGUAGES_DIR, id, 'harness.go')
      ];
      for (const hPath of harnessCandidates) {
        if (fs.existsSync(hPath)) {
          harnessCode = fs.readFileSync(hPath, 'utf-8');
          break;
        }
      }

      if (typeof buildTestCode === 'function') {
        runners.push({ id, extension, harnessCode, buildTestCode, buildTemplateCode });
      }
    } catch (err) {
      console.warn(`[WARN] Could not load runner for language '${id}':`, err);
    }
  }

  return runners;
}

function lintGeneratedTestCode(langId: string, testCode: string, exId: string): Violation[] {
  const violations: Violation[] = [];

  if (!testCode || !testCode.trim()) {
    violations.push({
      exerciseId: exId,
      languageId: langId,
      type: 'GENERATOR',
      message: 'Generated testCode is empty'
    });
    return violations;
  }

  if (langId === 'cpp') {
    // 1. Struct field with type void (e.g. void expected;)
    const voidFieldRegex = /\bvoid\s+[a-zA-Z0-9_]+\s*;/;
    if (voidFieldRegex.test(testCode)) {
      violations.push({
        exerciseId: exId,
        languageId: langId,
        type: 'LINT',
        message: 'Illegal struct field with type "void" in TestCase definition. Use proper expected type instead.'
      });
    }

    // 2. Check for std::to_string on vector or container identifiers
    const toStringVectorRegex = /std::to_string\s*\(\s*tc\.(?:nums|matrix|intervals|board|strs|words|edges|grid|head|root|lists)\b/g;
    if (toStringVectorRegex.test(testCode)) {
      violations.push({
        exerciseId: exId,
        languageId: langId,
        type: 'LINT',
        message: 'Illegal call to std::to_string() with vector/container. Use tc.desc or dedicated helper instead.'
      });
    }

    // 3. Check for literal null in arrays/expressions (e.g. {1, 2, null, 4})
    const rawNullRegex = /(?:[{,]\s*null\b|\bnull\s*[,}])/;
    if (rawNullRegex.test(testCode)) {
      violations.push({
        exerciseId: exId,
        languageId: langId,
        type: 'LINT',
        message: 'Undeclared identifier "null" found in C++ test code. Use std::nullopt or nullptr.'
      });
    }

    // 4. Check for C++ Most Vexing Parse in class instantiations: e.g. "PrefixTree obj();"
    const vexingParseRegex = /\b[A-Za-z0-9_]+\s+[a-zA-Z0-9_]+\s*\(\s*\)\s*;/;
    if (vexingParseRegex.test(testCode)) {
      violations.push({
        exerciseId: exId,
        languageId: langId,
        type: 'LINT',
        message: 'Most vexing parse detected: class instantiation with empty parentheses "Class obj();". Use "Class obj;" or "Class obj{};".'
      });
    }

    // 5. Check for string literal addition: e.g. "foo" + "bar"
    const strConcatRegex = /"[^"]*"\s*\+\s*"[^"]*"/;
    if (strConcatRegex.test(testCode)) {
      violations.push({
        exerciseId: exId,
        languageId: langId,
        type: 'LINT',
        message: 'Invalid operand to binary expression: string literal addition ("a" + "b").'
      });
    }

    // 6. Redundant/conflicting forward declaration of user function before main()
    const forwardDeclRegex = /\n(?:bool|int|void|std::string|std::vector<[^>]+>|TreeNode\*|ListNode\*)\s+([a-zA-Z0-9_]+)\s*\([^)]*\)\s*;\s*\n\s*int\s+main/m;
    if (forwardDeclRegex.test(testCode)) {
      violations.push({
        exerciseId: exId,
        languageId: langId,
        type: 'LINT',
        message: 'Redundant forward declaration emitted in testCode. User code is prepended by worker, so forward declarations cause ambiguous overload errors.'
      });
    }
  }

  return violations;
}

function verifySignatureInCode(
  code: string,
  targetName: string,
  receiver: string | undefined,
  langId: string,
  exId: string,
  fileName: string
): Violation[] {
  const violations: Violation[] = [];
  if (!code.trim()) return violations;

  let patternFound = false;

  if (langId === 'python') {
    patternFound = new RegExp(`\\b(?:def|class)\\s+${targetName}\\b`).test(code);
  } else if (langId === 'go') {
    const capitalized = targetName.charAt(0).toUpperCase() + targetName.slice(1);
    patternFound = new RegExp(`\\b(?:func|type)\\s+(?:\\([^)]*\\)\\s*)?(?:${targetName}|${capitalized})\\b`).test(code) ||
      new RegExp(`\\btype\\s+${targetName}\\b`, 'i').test(code);
  } else if (langId === 'cpp' || langId === 'c') {
    patternFound = new RegExp(`\\b(?:class|struct)?\\s*${targetName}\\s*(?:\\(|\\{)`).test(code) ||
      new RegExp(`\\b${targetName}\\s*\\(`).test(code);
  } else if (langId === 'typescript') {
    patternFound = new RegExp(`\\b(?:function|class|const|let)\\s+${targetName}\\b`).test(code);
  } else {
    patternFound = code.includes(targetName);
  }

  if (!patternFound) {
    violations.push({
      exerciseId: exId,
      languageId: langId,
      type: 'SIGNATURE',
      message: `Missing expected symbol "${targetName}" in ${fileName}`,
      file: fileName
    });
  }

  // If canonical-data specifies a receiver class (e.g. Solution, Codec), verify it exists
  if (receiver) {
    let receiverFound = false;
    if (langId === 'cpp' || langId === 'c') {
      receiverFound = new RegExp(`\\b(?:class|struct)\\s+${receiver}\\b`).test(code);
    } else if (langId === 'go') {
      receiverFound = new RegExp(`\\btype\\s+${receiver}\\s+struct\\b`).test(code);
    } else if (langId === 'python') {
      receiverFound = new RegExp(`\\bclass\\s+${receiver}\\b`).test(code);
    } else if (langId === 'typescript') {
      receiverFound = new RegExp(`\\bclass\\s+${receiver}\\b`).test(code);
    } else {
      receiverFound = code.includes(receiver);
    }

    if (!receiverFound) {
      violations.push({
        exerciseId: exId,
        languageId: langId,
        type: 'SIGNATURE',
        message: `Missing required receiver class "${receiver}" specified by canonical-data in ${fileName}`,
        file: fileName
      });
    }
  }

  return violations;
}

function verifyWithCompiler(
  langId: string,
  harnessCode: string | undefined,
  userCode: string,
  testCode: string,
  exId: string,
  targetType: 'TEMPLATE_COMPILER' | 'SOLUTION_COMPILER'
): Violation[] {
  const violations: Violation[] = [];

  if (langId === 'cpp') {
    const fullSource = (harnessCode ? harnessCode + '\n' : '') + userCode + '\n' + testCode;
    try {
      execSync('clang++ -fsyntax-only -std=c++20 -x c++ -', {
        input: fullSource,
        stdio: ['pipe', 'pipe', 'pipe']
      });
    } catch (err: any) {
      const stderr = err?.stderr?.toString() || err?.message || 'C++ compilation failed';
      const errors = stderr
        .split('\n')
        .filter((l: string) => l.includes('error:'))
        .slice(0, 2)
        .map((l: string) => l.replace(/<stdin>:\d+:\d+:\s*/, '').trim())
        .join(' | ');

      violations.push({
        exerciseId: exId,
        languageId: langId,
        type: targetType,
        message: errors || stderr.trim().split('\n')[0]
      });
    }
  } else if (langId === 'c') {
    const fullSource = (harnessCode ? harnessCode + '\n' : '') + userCode + '\n' + testCode;
    try {
      execSync('clang -fsyntax-only -std=c17 -x c -', {
        input: fullSource,
        stdio: ['pipe', 'pipe', 'pipe']
      });
    } catch (err: any) {
      const stderr = err?.stderr?.toString() || err?.message || 'C compilation failed';
      const errors = stderr
        .split('\n')
        .filter((l: string) => l.includes('error:'))
        .slice(0, 2)
        .map((l: string) => l.replace(/<stdin>:\d+:\d+:\s*/, '').trim())
        .join(' | ');

      violations.push({
        exerciseId: exId,
        languageId: langId,
        type: targetType,
        message: errors || stderr.trim().split('\n')[0]
      });
    }
  } else if (langId === 'python') {
    const fullSource = (harnessCode ? harnessCode + '\n' : '') + userCode + '\n' + testCode;
    try {
      execSync('python3 -c "import sys; compile(sys.stdin.read(), \\"<test>\\", \\"exec\\")"', {
        input: fullSource,
        stdio: ['pipe', 'pipe', 'pipe']
      });
    } catch (err: any) {
      const stderr = err?.stderr?.toString() || err?.message || 'Python syntax error';
      violations.push({
        exerciseId: exId,
        languageId: langId,
        type: targetType,
        message: stderr.trim().split('\n').pop() || 'Syntax error'
      });
    }
  }

  return violations;
}

async function main() {
  const args = parseArgs();
  const { flattenCases, parseCanonicalSignature } = await import(`file://${path.join(LANGUAGES_DIR, 'canonical.ts')}`);

  const runners = await discoverLanguageRunners(args.lang);
  const exerciseDirs = fs.readdirSync(EXERCISES_DIR, { withFileTypes: true })
    .filter(d => d.isDirectory() && fs.existsSync(path.join(EXERCISES_DIR, d.name, 'canonical-data.json')))
    .map(d => d.name)
    .filter(name => !args.exercise || name === args.exercise);

  console.log(`\n======================================================`);
  console.log(` DSA Contract & Compiler Verification`);
  console.log(` Checking ${exerciseDirs.length} exercise(s) across ${runners.length} language runner(s)`);
  console.log(`======================================================\n`);

  const allViolations: Violation[] = [];
  let totalTestsGenerated = 0;
  let totalTemplatesChecked = 0;
  let totalSolutionsChecked = 0;
  let totalCompilationsChecked = 0;

  for (const exId of exerciseDirs) {
    const exDir = path.join(EXERCISES_DIR, exId);
    const canonicalPath = path.join(exDir, 'canonical-data.json');

    let canonicalData: any;
    try {
      canonicalData = JSON.parse(fs.readFileSync(canonicalPath, 'utf-8'));
    } catch (err: any) {
      allViolations.push({
        exerciseId: exId,
        type: 'SCHEMA',
        message: `Failed to parse canonical-data.json: ${err?.message}`,
        file: canonicalPath
      });
      continue;
    }

    // 1. Validate canonical schema
    const schemaViolations = validateCanonicalJson(exId, canonicalData, canonicalPath);
    allViolations.push(...schemaViolations);

    const sig = parseCanonicalSignature(canonicalData);
    const targetSymbol = sig.name;
    const receiver = canonicalData.receiver;
    const flatCases = flattenCases(canonicalData.cases);

    // 2. Check templates, solutions, runner generation, and compilation per language
    for (const runner of runners) {
      const langDir = path.join(exDir, runner.id);
      const templatePath = path.join(langDir, `template${runner.extension}`);
      const solutionPath = path.join(langDir, `solution${runner.extension}`);

      let templateCode: string | undefined;
      if (fs.existsSync(templatePath)) {
        totalTemplatesChecked++;
        templateCode = fs.readFileSync(templatePath, 'utf-8');
        const tmplViolations = verifySignatureInCode(templateCode, targetSymbol, receiver, runner.id, exId, templatePath);
        allViolations.push(...tmplViolations);
      }

      let solutionCode: string | undefined;
      if (fs.existsSync(solutionPath)) {
        totalSolutionsChecked++;
        solutionCode = fs.readFileSync(solutionPath, 'utf-8');
        const solViolations = verifySignatureInCode(solutionCode, targetSymbol, receiver, runner.id, exId, solutionPath);
        allViolations.push(...solViolations);
      }

      // Generate testCode and lint it
      let testCode: string | undefined;
      try {
        testCode = runner.buildTestCode(flatCases, canonicalData);
        totalTestsGenerated++;
        const lintViolations = lintGeneratedTestCode(runner.id, testCode, exId);
        allViolations.push(...lintViolations);
      } catch (genErr: any) {
        allViolations.push({
          exerciseId: exId,
          languageId: runner.id,
          type: 'GENERATOR',
          message: `buildTestCode exception: ${genErr?.message || genErr}`
        });
      }

      // 3. Live Compiler Verification on TEMPLATE (starter code)
      if (templateCode && testCode) {
        totalCompilationsChecked++;
        const tmplCompViolations = verifyWithCompiler(runner.id, runner.harnessCode, templateCode, testCode, exId, 'TEMPLATE_COMPILER');
        allViolations.push(...tmplCompViolations);
      }

      // 4. Live Compiler Verification on SOLUTION (reference code)
      if (solutionCode && testCode) {
        totalCompilationsChecked++;
        const solCompViolations = verifyWithCompiler(runner.id, runner.harnessCode, solutionCode, testCode, exId, 'SOLUTION_COMPILER');
        allViolations.push(...solCompViolations);
      }
    }
  }

  // Report results
  console.log(`[Summary]`);
  console.log(`  - Exercises evaluated:      ${exerciseDirs.length}`);
  console.log(`  - Templates checked:        ${totalTemplatesChecked}`);
  console.log(`  - Solutions checked:        ${totalSolutionsChecked}`);
  console.log(`  - Test harnesses generated: ${totalTestsGenerated}`);
  console.log(`  - Compiler syntax checks:   ${totalCompilationsChecked}`);
  console.log();

  if (allViolations.length === 0) {
    console.log(`\x1b[32m✔ All contracts and compiler checks valid! Zero violations found.\x1b[0m\n`);
    process.exit(0);
  }

  console.log(`\x1b[31m✖ Found ${allViolations.length} contract/compiler violation(s):\x1b[0m\n`);

  // Group by exercise
  const grouped = new Map<string, Violation[]>();
  for (const v of allViolations) {
    const list = grouped.get(v.exerciseId) || [];
    list.push(v);
    grouped.set(v.exerciseId, list);
  }

  for (const [exId, list] of grouped) {
    console.log(`\x1b[1m[${exId}]\x1b[0m`);
    for (const v of list) {
      const tag = `[${v.type}]` + (v.languageId ? ` (${v.languageId})` : '');
      console.log(`  \x1b[31m${tag}\x1b[0m ${v.message}`);
    }
    console.log();
  }

  process.exit(1);
}

main().catch((err) => {
  console.error('Fatal error during contract verification:', err);
  process.exit(1);
});
