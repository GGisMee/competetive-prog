# Debugging Session Log: GDB & Nix Standard Library

**Date:** 2026-02-24
**Issue:** When debugging C++ code in VS Code (Nix environment), GDB steps into standard library header files (e.g., `basic_string.h`, `allocator.h`, `ostream`) located in `/nix/store/...`.

## Context
*   **OS:** Linux (NixOS/Nix shell)
*   **Compiler:** G++ 13.3.0 (via Nix)
*   **Debugger:** GDB 15.2 (via Nix)
*   **VS Code Configuration:** "C++ Launch" (cppdbg)

## Findings & Attempted Solutions

### 1. Simple Globbing (`skip -gfi`)
*   **Attempt:** `skip -gfi /nix/store/*`
*   **Result:** Failed. GDB's globbing is not recursive enough to catch files deep in `/nix/store/.../include/c++/13.3.0/bits/...`.

### 2. Regex File Skip (`skip -rfi`)
*   **Attempt:** `skip -rfi ^/nix/store/.*/include/.*`
*   **Result:** Failed. The specific GDB version or integration did not seem to respect this flag correctly, or syntax was rejected.

### 3. Regex Function Skip (`skip -rfu`) + Explicit Files
*   **Attempt:** `skip -rfu ^std::` combined with `skip file basic_string.h`.
*   **Observation:** worked in a simplified `gdb -batch` test on the CLI, but the user continued to experience stepping into headers in VS Code. This suggests either a VS Code integration quirk or inline code bypassing function skips.

### 4. Path Substitution (`set substitute-path`)
*   **Attempt:** `set substitute-path /nix/store /nonexistent`
*   **Result:** Prevented VS Code from opening the file (showing "File not found"), but GDB *still stopped* inside the functions, just without source code.

## Current Configuration (Active)
We are currently testing a "Nuclear Option" combining path substitution (to hide source) with aggressive, multi-level globbing to prevent stopping.

**Current `launch.json` `setupCommands`:**
1.  `set substitute-path /nix/store /ingensstans` (Hides source code)
2.  `skip -gfi /nix/store/*/include/*` (Level 1)
3.  `skip -gfi /nix/store/*/include/*/*` (Level 2)
4.  `skip -gfi /nix/store/*/include/*/*/*` (Level 3)
5.  `skip -gfi /nix/store/*/include/*/*/*/*` (Level 4)
6.  `skip -gfi /nix/store/*/include/*/*/*/*/*` (Level 5 - covers `bits/basic_string.h`)

## How to Resume
1.  Open VS Code.
2.  Ensure **"C++ Launch"** is selected in the Run/Debug sidebar.
3.  Start debugging (`F5`).
4.  Check the **Debug Console**. You should see the text: `LADDAR_SKIP_OCH_SUBSTITUTE`.
5.  **Test:** Step into (`F11`) code with `std::string` or `std::vector`.
    *   **Success:** Debugger moves to the next line of *your* code.
    *   **Failure:** Debugger stops with "File not found" error (meaning it stopped in stdlib but couldn't find source).

## Future Ideas if Current Config Fails
*   **Directory Exclusion:** Try the GDB `directory` command to explicitly remove standard include paths.
*   **Compilation Flags:** Recompile with `-g1` for standard libraries (difficult in Nix) or use specific pragmas.
*   **.gdbinit:** Move all logic to a `.gdbinit` file and force GDB to load it, bypassing VS Code's command passing mechanism.
