# Project Context

This page rebuilds the project's context from the evidence in the repository. Every statement is labeled:

- **Confirmed**: the files or the git history show it directly.
- **Inferred**: a reasonable deduction that the repository cannot prove.
- **Unknown**: the repository does not provide enough information to decide.

## Summary

| Question | Answer | Status |
|---|---|---|
| Project origin | **Unknown** | See [Origin](#origin) |
| What it is | Arduino sketches for a Wi-Fi board that runs an HTTP command server | Confirmed |
| Purpose | Control an LED, and later servos, with voice commands from a smartphone | Inferred |
| When | 2019-11-18 → 2019-11-20 | Confirmed (commit dates) |
| Who | `ArodPre` (v1), `OBaruch` (v2–v4) | Confirmed (commit authors) |
| Board | ESP32 | Inferred |
| Phone app | Exists but is not included | Mentioned in comments, otherwise unknown |

## Material available

When the reorganization started, the repository had only:

- `README.md` with the single line `# Modular_Arduino`, now kept as [original/README.original.md](original/README.original.md).
- `reconocimiento_de_voz.ino` on `master` (v1).
- Three branches that never reached `master` (`patch-1`, `patch-2`, `patch-3`), each holding a later version of the same sketch.

There were no PDFs, Word documents, slides, images, diagrams, datasets or generated outputs. The only sources of context were the code, its comments, the file and branch names, and the git metadata.

## Origin

**Project origin: Unknown.**

Evidence and what it suggests:

| Evidence | Suggests | Status |
|---|---|---|
| Original README title `Modular_Arduino` | "Modular" could mean a university *proyecto modular* (an integrative degree project at some Mexican universities). It could also just mean "modular". | Inferred, low confidence |
| Commit timezone UTC−06:00, Spanish identifiers and commands (`prender`, `navidad`, `baila`) | Developed by Spanish speakers, probably in Mexico | Inferred |
| Two contributors working over three consecutive days | A small collaborative project with a short deadline, or a quick build | Inferred |
| Commit `afde3a9 Merge pull request #1 from OBaruch/patch-1`, authored by `ArodPre` | v1 lived in a repository owned by `ArodPre`. `OBaruch` sent changes by pull request. This repository is a copy of that one. | Inferred from history |
| Branch `patch-3` commit message `AnimatronicoVersionDos` ("Animatronic Version Two") | The final goal was an animatronic | Confirmed that the message says so. The purpose is inferred. |

No course, subject, assignment, grading or report material exists. The documentation therefore makes no academic claims.

## Language of the comments

- Most of the comments in v1–v3 are in **Portuguese** (for example `lib necessária para conectar o wifi`, `exibe ip utilizado pelo ESP`).
- The lines added in the second commit, and later changes, are in **Spanish** (for example `Estas lineas se comentan para dejar la configuracion de IP dinamica`).
- **Inferred:** the base sketch was adapted from a Portuguese-language ESP32 + smartphone voice-control example, and the authors then customized it. The original source is **Unknown**.

## The smartphone app

Comments such as `mensagem enviada pelo client (aplicativo)` ("message sent by the client (app)") and `o mesmo deve ser usado no app do smartphone` ("the same [IP] must be used in the smartphone app") confirm that a phone app acted as the client. The file name `reconocimiento_de_voz` suggests that the app did the speech recognition and sent the recognized word as the URL path. The board does no speech processing (Confirmed from the code). The app's platform and source are **Unknown**.

## Scope

- **In scope (Confirmed):** Wi-Fi connection, a minimal HTTP server, parsing the command word, driving the LED and servos.
- **Out of scope (Confirmed absent):** speech recognition on the board, authentication, persistent state, a web UI, any build or test tooling.
- **Hardware wiring:** LED on GPIO 23 and servos on GPIO 18, 19 and 21 are confirmed from the code. Schematics, the power supply and the animatronic's mechanics are **Unknown**.

## Contradictions and open questions

- **Name:** the repository is now called `Snowy-Robot-1`, but the original README says `Modular_Arduino`. Neither name appears in the code.
- **Network settings:** v1 uses static IP `192.168.0.25` with gateway `192.168.3.255`. The gateway is outside the `/24` subnet of that IP, and a `.255` address is normally a broadcast address. v2–v4 use `192.168.43.211` (a range typical of Android hotspots, *inferred*) with the same gateway. Whether the static IP ever worked as intended is **Unknown**.
- **Command meanings:** in v2–v4 the words `navidad` ("Christmas"), `hora` ("time"), `luces` ("lights"), `baila` ("dance"), `si` ("yes") and `no` do not map to a documented behavior. v2–v3 wire them to LED patterns as placeholders. v4 implements only `no`. The intended final behavior is **Unknown**.
- **Which version is "the" project:** `master` holds only v1. The most complete work (v4) was never merged. All four versions are kept as equals. See [version-history.md](version-history.md).
