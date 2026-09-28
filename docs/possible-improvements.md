# Possible Improvements

> **None of these changes were applied.** The code in `src/` is kept exactly as it was written in 2019. This list only records what a modern review would point out. It is not a to-do list for the historical sketches. If any of it is ever implemented, it belongs in a separate new version folder or a new project, never in the original files.

## Security

- **Hard-coded Wi-Fi credentials.** Every version contains an SSID and password in plain text, and they are public in the git history. A modern version would keep them in an untracked `secrets.h` (already listed in `.gitignore`) or use a provisioning step. Any network whose password appears here should be treated as exposed.
- **No authentication.** Anyone on the same network can trigger commands with a plain `GET` request.

## Networking

- `gateway(192,168,3,255)` is not in the same subnet as the static IP, and `.255` is usually a broadcast address.
- `WiFi.config()` is called *after* `WiFi.begin()` has connected. On the ESP32 core, static settings are normally applied before connecting, so the static IP may not take effect as the comments expect.
- No reconnection logic. If Wi-Fi drops after `setup()`, the server does not recover.

## HTTP handling

- The command is extracted with fixed offsets (`remove(0,5)`, `remove(len-9,9)`). Any method other than `GET`, a query string or a nested path breaks it.
- `myresultat` is global and never cleared, so a malformed request can replay the previous command.
- `while(!client.available()) delay(1);` has no timeout, so a client that connects and sends nothing blocks the loop forever.
- The response always says `200 OK` and has no `Content-Length`. Unknown commands cannot be told apart from successful ones.
- Browsers also request `/favicon.ico`, which goes through the same code path.

## Code structure

- Blinking and servo sweeps use `delay()`, which blocks the server for about 2 s per command.
- The repeated, identical blink blocks in v1–v3 could be a single function.
- The chains of `if (ClientRequest == ...)` could be a lookup table.
- v4: `Serial.begin` is called twice; `ledVerde` is configured but never used; five commands have empty bodies.
- v4: because of the step size of 20, the upward loop stops at 160 and the downward loop runs from 179 to 19. Neither loop covers the full 0–179 range.

## Repository / tooling (possible future work, not added)

- A `platformio.ini` or `arduino-cli` sketch profile would pin the board, core and servo library versions. It was not added because the original versions are unknown and inventing them would misrepresent the project.
- Add a wiring diagram if the hardware is ever rebuilt.
