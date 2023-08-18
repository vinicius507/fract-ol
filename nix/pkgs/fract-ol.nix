{
  lib,
  stdenv,
  libX11,
  libXext,
  libft,
  minilibx,
}:
stdenv.mkDerivation {
  pname = "fract-ol";
  version = "0.1.0";
  src = ../../fract-ol;
  buildInputs = [
    libX11
    libXext
  ];
  buildPhase = ''
    export LIBFTDIR="${libft}"
    export MLXDIR="${minilibx}"

    make
  '';
  installPhase = ''
    mkdir -p $out/bin
    cp fractol $out/bin
  '';
  meta = with lib; {
    license = licenses.agpl3Only;
  };
}
