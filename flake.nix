{
  description = "Cpp development environment";

  inputs = {
    nixpkgs.url = "github:NixOS/nixpkgs/nixos-unstable";
    flake-utils.url = "github:numtide/flake-utils";
  };

  outputs = { self, nixpkgs, flake-utils }:
    flake-utils.lib.eachDefaultSystem (system:
      let pkgs = import nixpkgs { inherit system; };
      in {
        devShell = pkgs.mkShell {

          # Dependencies for project
          buildInputs = [
            pkgs.gcc
            pkgs.cmake
            pkgs.valgrind

            pkgs.yacc
            pkgs.flex
            pkgs.llvm
          ];

          # Links libraries to shell
          LD_LIBRARY_PATH = pkgs.lib.makeLibraryPath [
            pkgs.gcc
            pkgs.cmake
            pkgs.valgrind

            pkgs.llvm
          ];

          shellHook = ''
            echo ${pkgs.llvm}
            PS1="[\\u@\\h && CPP-DEV-ENV:\\w]\$ "
          '';
        };
      });
}
