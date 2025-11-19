{
  description = "Cpp development environment";

  inputs = {
    nixpkgs.url = "github:NixOS/nixpkgs/nixos-25.05";
    flake-utils.url = "github:numtide/flake-utils";
  };

  outputs = { self, nixpkgs, flake-utils }:
    flake-utils.lib.eachDefaultSystem (system:
      let pkgs = import nixpkgs { inherit system; };
      in {
        devShell = pkgs.mkShell {

          nativeBuildInputs = [
            #
            pkgs.gcc
            pkgs.cmake
            pkgs.bison
            pkgs.flex
            pkgs.valgrind
          ];

          buildInputs = [
            #
            pkgs.libgcc
            pkgs.glibc
            pkgs.glibc.dev
            pkgs.libgccjit
          ];

          #links libraries to shell
          LD_LIBRARY_PATH = pkgs.lib.makeLibraryPath [
            #
            pkgs.libgcc
            pkgs.glibc.dev
            pkgs.glibc
            pkgs.libgccjit
          ];

          shellHook = ''
            PS1="[\\u@\\h && CPP-DEV-ENV:\\w]\$ "
            export LIBRARY_PATH=${pkgs.glibc}/lib
          '';
        };
      });
}
