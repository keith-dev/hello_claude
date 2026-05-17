# hello_claude — Project Status

## What it does
Translates "Hello World" into a language specified on the command line, using the Google Translate API over HTTP.

```sh
./build/hello fr   # Bonjour le monde
./build/hello de   # Hallo Welt
./build/hello ja   # こんにちは世界
```

## Build
```sh
env -u CC -u CXX cmake -B build
cmake --build build
```

> Note: `CC`/`CXX` env vars must be unset at configure time — they point to Intel `icx-cc`/`icpx` which is not installed on this system.

## Dependencies
| Dependency | Source | Version |
|---|---|---|
| libcurl | system | 8.14.1 |
| nlohmann/json | FetchContent (GitHub) | 3.11.3 |

## Compiler
GCC 14.2.0 (system default). Clang 19.1.7 also available.

## Files
| File | Purpose |
|---|---|
| `main.cpp` | Program entry point — calls translate API, prints result |
| `CMakeLists.txt` | Build config — C++20, fetches nlohmann/json, links curl |
| `build/` | CMake build output (not tracked) |

## API
Uses the unofficial Google Translate endpoint:
```
https://translate.googleapis.com/translate_a/single?client=gtx&sl=en&dt=t&q=Hello+World&tl={lang}
```
Response format: `[[[translated_text, original, ...], ...], ...]` — text is at `[0][0][0]`.

## Notes
- Do not use Boost.JSON — fails at large volumes; use nlohmann/json, RapidJSON, or simdjson instead
- Control flow (`if`, `for`, `while`, etc.) must always use braces; body always on its own line, never same-line

## History
- Started as a plain hello world (C++20, CMake)
- Added online translation via MyMemory API
- Switched to Google Translate endpoint after MyMemory returned incorrect results (Persian for `fr`)
- Added "collaborated" human-input badge to README (2026-05-18); from [keith-dev/badges-repo](https://github.com/keith-dev/badges-repo)
