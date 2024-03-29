/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 22:04:26 by vgoncalv          #+#    #+#             */
/*   Updated: 2021/07/22 22:04:26 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <mlx.h>
# include "libft.h"
# include "ft_complex.h"

# define MAX_ITER 80
# define ZOOM_STEP 0.05L
# define AXIS_RANGE 2.0L

typedef struct s_image
{
	void	*image;
	char	*data;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
}	t_image;

/* Fractol Data Structure. `w_size` refers to the  width and height of
 * `window`. `z` and `c` are `t_complex` numbers for generating the fractals,
 * in which `c` refers to the current coordinate being evaluated. `radius`
 * refer to the interval shown in each axis. `data` refers to the pixelmap. */
typedef struct s_fractol
{
	char		*fractol;
	int			width;
	int			height;
	void		*mlx;
	void		*window;
	t_complex	z;
	t_complex	c;
	long double	factor_x;
	long double	factor_y;
	long double	offset_x;
	long double	offset_y;
	long double	scale;
	int			*data;
	t_image		*image;
	int			(*fn)();
}	t_fractol;

/* Exit Codes for `fractol` */
typedef enum e_error
{
	UNKNOWN_ARG	= 1<<0,
	NO_ARG = 1<<1,
	NO_FRACTAL_OPTIONS = 1<<2,
	INVALID_FRACTAL_OPTIONS = 1<<3,
	SYS_ERROR = 1<<4,
	MLX_INIT_ERROR = 1<<5,
	MLX_WINDOW_ERROR = 1<<6,
	MLX_IMAGE_ERROR = 1<<7,
}	t_error;

/* Prints help message on the cli. */
void		print_help(const char *fractol);

/* Parses arguments passed to the program. */
void		argparse(int argc, char **argv, t_fractol *fractol);

/* Parses fractal arguments. */
void		get_fractal_args(char *opt, t_fractol *fractol);

/* Iterates a complex number to check if it is part of the Mandelbrot Set */
int			mandelbrot(t_fractol *fractol);

/* Iterates a complex number to check if it is part of the Julia Set */
int			julia(t_fractol *fractol);

/* Iterates a complex number to check if it is part of the Mandelbar
 * Set(Tricorn) */
int			mandelbar(t_fractol *fractol);

/* Sets default values for `t_fractol`. */
void		set_defaults(t_fractol *fractol);

/* Sets default viewport for `t_fractol`. */
void		set_default_viewport(t_fractol *fractol);

/* Initializes `fractol` */
void		init(t_fractol *fractol);

/* Registers fractol keys */
void		register_keys(t_fractol *fractol);

/* Terminates fractol */
void		kill(t_fractol *fractol, int code);

/* Raises an `t_error` and terminates the program */
void		raise(t_error code, const char *argument, t_fractol *fractol);

/* Translates pixel coordinates to complex plane point */
t_complex	translate(int x, int y, t_fractol *fractol);

/* Gets the color for the number of iterations */
int			get_color(int iteration);

/* Displays the fractal */
int			display_fractal(t_fractol *fractol);

/* Handles the computation of zoom parameters */
void		zoom(int z, t_fractol *fractol, int mouse_x, int mouse_y);

#endif
