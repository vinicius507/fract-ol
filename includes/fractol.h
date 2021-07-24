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

void	print_help(const char *fractol);

void	argparse(int argc, char **argv, t_fractol *fractol);

int		mandelbrot(t_fractol *fractol);

int		julia(t_fractol *fractol);

void	set_defaults(t_fractol *fractol);

#endif
