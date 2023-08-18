<p align="center">
    <img src="https://game.42sp.org.br/static/assets/achievements/fract-olm.png">
</p>

<p align="center">
    <img src="https://img.shields.io/badge/OS-Linux-blue" alt="OS">
    <img src="https://img.shields.io/badge/Language-C-orange.svg" alt="Language">
    <img src="https://img.shields.io/badge/Grade-125%2F100-brightgreen.svg" alt="Grade">
    <img src="https://img.shields.io/badge/Status-Completed-brightgreen.svg" alt="Status">
</p>

# Fract-ol
[![build](https://github.com/vinicius507/fract-ol/actions/workflows/build.yml/badge.svg)](https://github.com/vinicius507/fract-ol/actions/workflows/build.yml)
[![norminette](https://github.com/vinicius507/fract-ol/actions/workflows/norminette.yml/badge.svg)](https://github.com/vinicius507/fract-ol/actions/workflows/norminette.yml)

This repository contains my submission to the Fract-ol project for 42 School.
It provides a (single-threaded) fractal visualizer with _ok_ performance.

![Some visualizations from the Fractol Program](/assets/fractol.gif)

## Introduction
The **fractol** program provides visualization of the following fractals:

- Mandelbrot Set
- Julia Set (parametrized)
- Mandelbar Set

## Usage
To use the **fractol** program, follow these steps:

1. Clone this repository to your local machine.
2. Navigate to the repository's root directory.
3. Run `make` to compile the library.

A compiled binary named `fractol` will be generated.

```sh
$ ./fractol --help
Usage: ./fractol FRACTAL [FRACTAL_OPTIONS]

Available fractals are: Mandelbrot, Julia, Mandelbar

Some fractals require options to work:
	Julia	Receives a complex number in the following form: 0.0+0.0i
```

### Controls
You can control the **fractol** program by using the following keybindings:

- Navigate the fractal using `WASD` or arrow keys.
- Zoom in or out from the fractal using the mouse wheel.
- Restore the viewport using the `R` key.
- `Q` or `ESQ` to exit the program.
