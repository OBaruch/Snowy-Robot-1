# Contributor & Agent Guidelines

These rules apply to every contributor, human or automated.

## Hard rules

1. **Do not modify anything under `src/`.** The `.ino` sketches are the original 2019 implementation and are kept byte-for-byte, including their bugs, comments, style and hard-coded values. Their SHA-256 hashes are listed in [docs/version-history.md](docs/version-history.md).
2. **Do not reformat, lint or "fix" the sketches**, even when a tool suggests it.
3. **Do not delete historical material**: the files in `docs/original/` and the `archive/*` tags.
4. **Do not invent context.** Label every claim in the docs as Confirmed, Inferred or Unknown.
5. **Do not quote credentials** that appear in the sketches.

## Allowed changes

- Documentation in `README.md` and `docs/`.
- Repository hygiene such as `.gitignore`.
- New work goes in a *new* folder, for example a future `src/v5-.../`, and the change is recorded in `docs/version-history.md`.

## Workflow

Non-trivial changes follow **intent → spec → plan**. See [docs/sdlc/](docs/sdlc/). Update those files, or add new ones, before implementing.

## Verification before committing

```bash
sha256sum src/*/*/*.ino   # must match docs/version-history.md
```
