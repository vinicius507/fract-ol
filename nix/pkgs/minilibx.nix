{
  lib,
  stdenv,
  fetchFromGitHub,
  libX11,
  libXext,
}:
stdenv.mkDerivation {
  name = "minilibx";
  src = fetchFromGitHub {
    owner = "42Paris";
    repo = "minilibx-linux";
    rev = "7dc53a411a7d4ae286c60c6229bd1e395b0efb82";
    hash = "sha256-aRYMpaPC7dC6EHmmXugvwcQnaizRCQZKFcQX0K2MLM4=";
  };
  buildInputs = [
    libX11
    libXext
  ];
  dontConfigure = true;
  makefile = "Makefile.mk";
  makeFlags = [
    "CC=${stdenv.cc.targetPrefix}cc"
  ];
  installPhase = ''
    mkdir -p $out/{include,lib}
    cp mlx*.h $out/include
    cp libmlx*.a $out/lib
  '';
  meta = with lib; {
    description = "A simple X-Window (X11R6) programming API in C";
    homepage = "https://github.com/42Paris/minilibx-linux";
    license = licenses.bsd2;
    platforms = platforms.unix;
  };
}
