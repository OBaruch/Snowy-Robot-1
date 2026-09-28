# Intent: Historical Repository Reorganization

> Part of the spec-driven workflow for this repository: **intent** (why) → [spec](spec.md) (what) → [plan](plan.md) (how).

## Why

This repository holds a small 2019 ESP32 project: Wi-Fi voice commands sent from a phone app to drive an LED and later animatronic servos. Before the reorganization it was hard to understand or present:

- The README was one line (`# Modular_Arduino`).
- The only file on `master` was the earliest version of the sketch.
- The most complete work (the servo animatronic) existed only on three stale, unmerged branches (`patch-1..3`) that are easy to lose.
- Nothing explained what the code does, how the versions relate, or what context it came from.

## Desired outcome

A repository that works as an **honest historical record** in a technical portfolio:

1. Someone can understand the project from the README without opening the code.
2. Every version of the original code is visible, byte-for-byte, in one place.
3. Context is documented with its evidence level (Confirmed / Inferred / Unknown).
4. Old branches are closed without losing any commit or authorship.

## Principles

- **Modernize the repository, not the project.** Documentation and layout may follow current practice. The code may not change.
- **Preservation over cleanup.** When unsure, keep it.
- **No invented facts.** No made-up course, board model, library versions, build steps or app details.
- **No artificial complexity.** No CI, containers, package managers or build tooling that the original project never had.

## Non-goals

- Fixing, formatting or modernizing the `.ino` sketches.
- Making the project compile on current toolchains.
- Removing the hard-coded credentials from the code or from the git history. This is flagged for the owner in [possible-improvements.md](../possible-improvements.md).
- Rebuilding the missing smartphone app.
