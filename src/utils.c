/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 18:04:30 by vgoncalv          #+#    #+#             */
/*   Updated: 2021/07/23 18:04:30 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	print_help(const char *fractol)
{
	printf("Usage: %s FRACTAL [FRACTAL_OPTIONS]\n\n"
		"Available fractals are: Mandelbrot, Julia, Mandelbar\n\n"
		"Some fractals require options to work:\n"
		"\tJulia\tReceives a complex number in the following form: 0.0+0.0i\n",
		fractol);
}

void	kill(t_fractol *fractol, int code)
{
	if (fractol->image)
	{
		if (fractol->image->image)
			mlx_destroy_image(fractol->mlx, fractol->image->image);
		free(fractol->image);
	}
	if (fractol->window)
		mlx_destroy_window(fractol->mlx, fractol->window);
	if (fractol->mlx)
	{
		mlx_destroy_display(fractol->mlx);
		free(fractol->mlx);
	}
	exit(code);
}
