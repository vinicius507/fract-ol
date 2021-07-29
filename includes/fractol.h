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
# include "error.h"

# define MAX_ITER 80

/* Fractol Data Structure. The `width` and the `height` refer to the `window`
 * geometry. `z` and `c` are `t_complex` numbers for generating the fractals,
 * in which `c` refers to the current coordinate being evaluated. */
typedef struct s_fractol
{
	int			width;
	int			height;
	void		*mlx;
	void		*window;
	t_complex	z;
	t_complex	c;
	int			(*fractal)();
}	t_fractol;

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

#endif
