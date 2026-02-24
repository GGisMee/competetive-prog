{ pkgs ? import <nixpkgs> {} }:

let
  # Skapa en riktig körbar fil istället för ett alias
  gpp = pkgs.writeShellScriptBin "gpp" ''
    exec ${pkgs.gcc}/bin/g++ -std=c++20 "$@"
  '';
in
pkgs.mkShell {
  buildInputs = with pkgs; [
    gpp           # Vårt nya kommando
    gcc
    gdb
    clang-tools
    cmake
    gnumake
  ];

  shellHook = ''
    export CC=gcc
    export CXX=g++
  '';
}