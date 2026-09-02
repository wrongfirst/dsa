# Adding & Structuring Exercises

Each exercise lives in a topic folder under `src/exercises/` (e.g. `hello_world/`). It contains a shared problem description (`problem.md`) and subdirectories for language variants.

---

## Exercise Directory Structure

```text
src/exercises/hello_world/
├── canonical-data.json  # Canonical test data (Exercism JSON schema)
├── problem.md           # Problem description (Markdown - first line "# Hello World" is the title)
├── ocaml/
│   ├── template.ml      # Starter code for OCaml
│   └── solution.ml      # Solution code for OCaml
└── c/
    ├── template.c       # Starter code for C
    └── solution.c       # Solution code for C
```

---

### Adding a New Language Variant to an Exercise
To add a language variant to an existing exercise:
1. Run `npm run gen:templates -- --exercise=<id> --lang=<lang_id>` to generate `template.<ext>`.
2. Add `solution.<ext>` implementing the exact starter template signature.
3. Validate using `npm run verify:contracts -- --exercise=<id>`.

For the complete guide on adding problems and canonical data, see:
- [Adding a New Problem](../../docs/ADDING_A_NEW_PROBLEM.md)
- [Adding a New Type Mapping](../../docs/ADDING_A_NEW_TYPE_MAPPING.md)
- [Adding a New Language](../../docs/ADDING_A_NEW_LANGUAGE.md)

---

## Registering & Ordering in Curriculum (`curriculum.yaml`)

Curriculum ordering, chapters, active exercises, and drafts are defined in `src/exercises/curriculum.yaml`.

```yaml
chapters:
  "Basics":
      - hello_world
      - ints_vs_floats
      - functions
      - conditionals
      - tuples
      # - lists
      # - arrays
      # - strings

  "Key Concepts":
      - currying
      # - pure_functions
      # - immutability
      # - side_effects

  # "Intermediate Concepts"
  #     - memoization
  #     - tail_recursion
```

- **Draft Exercises & Chapters**: Disable upcoming exercises or chapters by commenting them out with `#`. Un-comment when ready to release.

---

## NOTE

> **Language availability is exercise-driven in the UI**:
> Enabling a language in `site.toml` registers the compiler/runner site-wide. However, the UI Language Selector dropdown evaluates availability per exercise.
>
> If a language is enabled in `site.toml` (e.g. `c` or `python`), but an exercise directory does not contain a subfolder for that language (e.g. `hello_world/c/`), **the UI dropdown will NOT show or enable that language for that exercise**.