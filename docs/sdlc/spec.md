# Spec: Historical Repository Reorganization

> [intent](intent.md) → **spec** → [plan](plan.md)

## Baseline (state before the change)

| Ref | Content |
|---|---|
| `master` @ `8b2b0dd` | `README.md` (`# Modular_Arduino`), `reconocimiento_de_voz.ino` (v1) |
| `patch-1` @ `be09e0d` | v2 sketch |
| `patch-2` @ `21645a3` | v3 sketch |
| `patch-3` @ `cbef0bd` | v4 sketch (servos) |
| Pull requests | none open |

## Requirements

### R1: Code preservation (MUST)
- R1.1 Every `.ino` file in `src/` is byte-identical to its source blob. The SHA-256 values are listed in [version-history.md](../version-history.md).
- R1.2 No source file is edited, reformatted or renamed. Moving it into a folder is allowed, and the folder name must match the sketch name so the Arduino IDE can open it.
- R1.3 v1 is moved with `git mv` so that `git log --follow` keeps its history.

### R2: Version consolidation (MUST)
- R2.1 v1–v4 live side by side under `src/vN-<short-description>/reconocimiento_de_voz/`.
- R2.2 Each version is traceable to its original ref, commit, author and date.

### R3: Documentation (MUST)
- R3.1 `README.md` covers: overview, context, problem, objective, structure, original-implementation note, technologies, how it works, inputs and outputs, running (marked as inferred), documentation links and a historical note.
- R3.2 `docs/project-context.md` labels each fact Confirmed / Inferred / Unknown and lists contradictions.
- R3.3 `docs/code-overview.md` explains each version without changing it.
- R3.4 `docs/version-history.md` maps versions to refs and hashes.
- R3.5 `docs/possible-improvements.md` states clearly that nothing listed in it was applied.
- R3.6 The original README is kept under `docs/original/`.
- R3.7 The documentation does not repeat the Wi-Fi credentials found in the code.
- R3.8 All documentation is in English and uses relative links.

### R4: Branch hygiene (MUST)
- R4.1 Each stale `patch-*` branch head is kept as an annotated tag `archive/<branch>` before the branch is deleted.
- R4.2 After cleanup, the remote has only `master` and the working branch for this change.

### R5: Minimal tooling (MUST NOT)
- R5.1 No CI, Docker, Makefile, package manager, linters, formatters or test frameworks are added.
- R5.2 Only a small `.gitignore` and an `AGENTS.md` with contributor guardrails are added.

## Acceptance criteria

- [ ] `sha256sum src/*/*/*.ino` matches the table in `version-history.md`.
- [ ] `git log --follow src/v1-led-voice-commands/reconocimiento_de_voz/reconocimiento_de_voz.ino` shows the 2019 commits.
- [ ] `git show archive/patch-{1,2,3}` resolves to `be09e0d`, `21645a3` and `cbef0bd`.
- [ ] `git ls-remote --heads origin` lists no `patch-*` branches.
- [ ] Every relative link in the Markdown files resolves.
- [ ] `grep` finds no Wi-Fi password string in `*.md`.
