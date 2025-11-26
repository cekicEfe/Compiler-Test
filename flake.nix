{
  description = "Cpp development environment";

  inputs = {
    nixpkgs.url = "github:NixOS/nixpkgs/nixos-25.05";
    flake-utils.url = "github:numtide/flake-utils";
  };

  outputs = { self, nixpkgs, flake-utils }:
    flake-utils.lib.eachDefaultSystem (system:
      let
        pkgs = import nixpkgs { inherit system; };
        bdwgc = pkgs.boehmgc.overrideAttrs (old: {
          version = "7.6.6";
          src = pkgs.fetchFromGitHub {
            owner = "bdwgc";
            repo = "bdwgc";
            rev = "a8bd4189437eb08bce0f9bba1750d6c7a2d89a7d";
            sha256 = "sha256-D9rLdsy1SEsk0T5e03R6NRBx9MeXP05dHnPQkxhgAgo=";
          };
        });
      in {
        packages.bdwgc = bdwgc;

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
            bdwgc
            pkgs.libgcc
            pkgs.glibc
            pkgs.glibc.dev
            pkgs.libgccjit
          ];

          #links libraries to shell
          LD_LIBRARY_PATH = pkgs.lib.makeLibraryPath [
            #
            bdwgc
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
