# Plan: Historical Repository Reorganization

> [intent](intent.md) → [spec](spec.md) → **plan**

## Steps

| # | Step | Satisfies | Status |
|---|---|---|---|
| 1 | Audit the repository: files, commit history, all remote branches, open PRs | Baseline | Done |
| 2 | Read every sketch version and diff the branches against `master` | R2, R3.3 | Done |
| 3 | Record the SHA-256 of each source blob | R1.1 | Done |
| 4 | `git mv` v1 into `src/v1-led-voice-commands/reconocimiento_de_voz/` | R1.2, R1.3 | Done |
| 5 | Export v2–v4 with `git show <branch>:reconocimiento_de_voz.ino` into their `src/` folders and verify the hashes | R1.1, R2.1 | Done |
| 6 | Move the original README to `docs/original/README.original.md` | R3.6 | Done |
| 7 | Write the README, project-context, code-overview, version-history and possible-improvements docs | R3 | Done |
| 8 | Add `.gitignore` and `AGENTS.md` | R5.2 | Done |
| 9 | Check hashes, links and that no credentials appear in the docs | Acceptance | Done |
| 10 | Commit on a feature branch and open a pull request against `master` | — | Done |
| 11 | Create and push annotated tags `archive/patch-1..3`, then delete the remote `patch-*` branches | R4 | Done |

## Decisions

| Decision | Alternatives considered | Reason |
|---|---|---|
| Keep all four versions in `src/` as equals | Keep only v1 or only v4; put the others in `archive/` | No version is the "canonical" one: `master` has v1, but v4 is the most complete. A flat version list is the most honest layout. |
| One folder per sketch named `reconocimiento_de_voz/` | Rename the files per version | Renaming source files would break R1.2. The Arduino IDE requires the folder and file names to match. |
| Tags plus file copies before deleting branches | Keep the branches open; delete them without tags | The branches were stale and unmerged. The tags keep the exact commits and authorship, and the copies make the code visible. |
| No `architecture.md` | Separate architecture doc | The system is one sketch plus an external app. A sequence diagram in the README and a flowchart in the code overview are enough. |
| No build files (`platformio.ini` etc.) | Add a pinned build profile | The original board, core and library versions are unknown, so pinning them would invent facts. |

## Risks

| Risk | Mitigation |
|---|---|
| Losing branch-only history | Annotated tags pushed *before* the branches are deleted |
| Changing source bytes by accident (line endings, encoding) | Hash comparison against the original blobs |
| Spreading secrets further | The docs refer to credentials but never quote them. Rotating the credentials is left to the owner. |
