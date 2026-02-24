# Gemini Project Context: C++ Competitive Programming & Experiments

## Project Overview
This directory contains a collection of C++ source files, primarily focused on solving competitive programming problems (specifically from Kattis) and general C++ experiments. The environment is managed using Nix and direnv to ensure consistent tooling.

## Environment Setup
The project uses **Nix** to provide the development environment.
*   **Dependencies:** `gcc` (g++), `gdb`, `clang-tools`, `cmake`, `gnumake`.
*   **Shell:** A `shell.nix` file is provided.
*   **Direnv:** `.envrc` is present, suggesting `direnv` is used to automatically load the Nix shell upon entering the directory.

## Building and Running
### Compilation
The project is configured to use `C++20`.

**VS Code Task:**
There is a configured VS Code build task ("Nix G++ build") that compiles the currently open file:
```bash
g++ -std=c++20 -g <filename>.cpp -o <filename_without_extension>
```

**Custom Command:**
The `shell.nix` file defines a convenience command `gpp` which wraps `g++`:
```bash
gpp <filename>.cpp -o <output_name>
# Equivalent to: g++ -std=c++20 <filename>.cpp -o <output_name>
```

### Running
After compilation, run the resulting binary directly:
```bash
./<filename_without_extension>
```

## Key Files
*   `shell.nix`: Nix expression defining the development environment and the `gpp` wrapper script.
*   `.vscode/tasks.json`: VS Code build task configuration.
*   `kattis_*.cpp`: Solutions to specific Kattis problems (e.g., `kattis_bokiboba.cpp`, `kattis_boxes.cpp`).
*   `gitgood.cpp`, `mumble_rap.cpp`: Likely other problem solutions or experiments.

## Development Conventions
*   **Language Standard:** C++20.
*   **Input/Output:** Standard `std::cin` and `std::cout` are used for IO, consistent with competitive programming practices.
*   **Structure:** Solutions are generally single-file implementations.
