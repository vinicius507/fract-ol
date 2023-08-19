{
  inputs = {
    nixpkgs.url = "nixpkgs";
    ft-nix = {
      url = "github:vinicius507/42-nix";
      inputs.nixpkgs.follows = "nixpkgs";
    };
    libft = {
      url = "github:vinicius507/libft";
      inputs.nixpkgs.follows = "nixpkgs";
    };
  };
  outputs = {
    self,
    nixpkgs,
    ft-nix,
    libft,
  }: let
    allSystems = [
      "x86_64-linux"
      "aarch64-linux"
    ];
    forEachSystem = f:
      nixpkgs.lib.genAttrs allSystems (system:
        f {
          pkgs = import nixpkgs {
            inherit system;
            overlays = [
              ft-nix.overlays.norminette
              libft.overlays.libft
              self.overlays.fract-ol
              self.overlays.minilibx
            ];
          };
        });
  in {
    checks = forEachSystem ({pkgs}: {
      norminette-check = pkgs.stdenvNoCC.mkDerivation {
        name = "norminette-check";
        src = ./fract-ol;
        dontBuild = true;
        doCheck = true;
        checkPhase = with pkgs; ''
          ${norminette}/bin/norminette $src
        '';
        installPhase = "touch $out"; # Derivation must build an output.
      };
    });
    packages = forEachSystem ({pkgs}: {
      default = pkgs.fract-ol;
      fract-ol = import ./nix/pkgs/fract-ol.nix {
        inherit (pkgs) lib libft minilibx;
        inherit (pkgs.xorg) libX11 libXext;
        inherit (pkgs.llvmPackages_12) stdenv;
      };
      minilibx = import ./nix/pkgs/minilibx.nix {
        inherit (pkgs) lib stdenv fetchFromGitHub;
        inherit (pkgs.xorg) libX11 libXext;
      };
    });
    overlays = {
      default = self.overlays.fract-ol;
      fract-ol = final: _: {
        fract-ol = self.packages.${final.system}.fract-ol;
      };
      minilibx = final: _: {
        minilibx = self.packages.${final.system}.minilibx;
      };
    };
    devShells = forEachSystem ({pkgs}: let
      mkShell = pkgs.mkShell.override {inherit (pkgs.llvmPackages_12) stdenv;};
    in {
      default = mkShell {
        packages = with pkgs; [
          bear
          clang-tools_12
          gnumake
          norminette
          valgrind
        ];
      };
    });
  };
}
