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

# include "libft.h"
# include "ft_complex.h"
# include "mlx.h"

# define MAX_ITER 80

/* Fractol Data Structure. The `width` and the `height` refer to the `window`
 * geometry. `z` and `c` are `t_complex` numbers for generating the fractals,
 * in which `c` refers to the current coordinate being evaluated. `radius` refer
 * to the interval shown in each axis. `data` refers to the pixelmap. */
typedef struct s_fractol
{
	char		*fractol;
	int			width;
	int			height;
	void		*mlx;
	void		*window;
	t_complex	z;
	t_complex	c;
	long double	radius;
	int			*data;
	int			(*fractal)();
}	t_fractol;

/* Exit Codes for `fractol` */
typedef enum e_error
{
	UNKNOWN_ARG	= 1<<0,
	NO_ARG = 1<<1,
	NO_FRACTAL_OPTIONS = 1<<2,
	INVALID_FRACTAL_OPTIONS = 1<<3,
	SYS_ERROR = 1<<4,
}	t_error;

/* Prints help message on the cli. */
void	print_help(const char *fractol);

/* Parses arguments passed to the program. */
void	argparse(int argc, char **argv, t_fractol *fractol);

/* Iterates a complex number to check if it is part of the Mandelbrot Set */
int		mandelbrot(t_fractol *fractol);

/* Iterates a complex number to check if it is part of the Julia Set */
int		julia(t_fractol *fractol);

/* Sets default values for `t_fractol`. */
void	set_defaults(t_fractol *fractol);

/* Initializes `fractol` */
void	init(t_fractol *fractol);

/* Registers fractol keys */
void	register_keys(t_fractol *fractol);

/* Terminates fractol */
void	kill(t_fractol *fractol, int code);

/* Raises an `t_error` and terminates the program */
void	raise(t_error code, const char *argument, t_fractol *fractol);

#endif
