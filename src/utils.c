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
		"Fractal options are: Mandelbrot, Julia\n\n"
		"Some fractals require options to work:\n"
		"\tJulia\tReceives a complex number in the following form: 0.0+0.0i",
		fractol);
}

void	set_defaults(t_fractol *fractol)
{
	fractol->fractol = "fractol";
	fractol->fractal = NULL;
	fractol->mlx = NULL;
	fractol->window = NULL;
	fractol->image = NULL;
	fractol->w_size = 800;
	fractol->c = assign(0, 0);
	fractol->z = assign(0, 0);
	fractol->radius = 2.0L;
	fractol->mouse_x = 0.0L;
	fractol->mouse_y = 0.0L;
}

void	kill(t_fractol *fractol, int code)
{
	if (fractol->image)
	{
		if (fractol->image->image)
			mlx_destroy_image(fractol->mlx, fractol->image->image);
		free(fractol->image);
	}
	exit(code);
}
