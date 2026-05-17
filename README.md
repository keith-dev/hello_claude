# hello_claude

![human input: collaborated](https://raw.githubusercontent.com/keith-dev/badges-repo/master/badge-collaborated.svg)

Translates "Hello World" into any language using the Google Translate API.

## Usage

```sh
./build/hello <language-code>
```

Examples:

```sh
./build/hello fr   # Bonjour le monde
./build/hello de   # Hallo Welt
./build/hello ja   # こんにちは世界
./build/hello es   # Hola Mundo
```

Language codes follow the [ISO 639-1](https://en.wikipedia.org/wiki/List_of_ISO_639_language_codes) standard.

## Build

Requires CMake 3.20+, a C++20 compiler, and libcurl.

```sh
cmake -B build
cmake --build build
```

## Dependencies

| Library | Source | Version |
|---|---|---|
| libcurl | system | — |
| [nlohmann/json](https://github.com/nlohmann/json) | FetchContent | 3.11.3 |

## Docs

- [docs/status.md](docs/status.md) — project status, API details, and history
