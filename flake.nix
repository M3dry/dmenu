{
  inputs = {
    nixpkgs.url = "github:nixos/nixpkgs/nixos-unstable";
    flake-utils.url = "github:numtide/flake-utils";
  };

  outputs = {
    nixpkgs,
    flake-utils,
    ...
  }:
    flake-utils.lib.eachDefaultSystem (
      system: let
        pkgs = nixpkgs.legacyPackages.${system};
        dmenu = pkgs.stdenv.mkDerivation {
          pname = "dmenu";
          version = "5.3";
          src = ./.;
          buildInputs = with pkgs; [
            xorg.libX11
            xorg.libXrender
            xorg.libXinerama
            xorg.libXft
            fontconfig
            zlib
            pkg-config
          ];
          preConfigure = ''
            makeFlagsArray+=(
              PREFIX="$out"
              CC="$CC"
              INCS="-I${pkgs.fontconfig} -I${pkgs.xorg.libX11} -I${pkgs.xorg.libXft} -I${pkgs.xorg.libXinerama} -I${pkgs.xorg.libXrender}"
            )
          '';
        };
      in {
        packages.default = dmenu;
        apps = {
          default = flake-utils.lib.mkApp {
            drv = dmenu;
            exePath = "/bin/dmenu";
          };
          run = flake-utils.lib.mkApp {
            drv = dmenu;
            exePath = "/bin/dmenu_run";
          };
        };
      }
    );
}
