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
	fractol->width = 1200;
	fractol->height = 600;
	if (fractol->width <= fractol->height)
	{
		fractol->offset_x = AXIS_RANGE;
		fractol->offset_y = AXIS_RANGE * fractol->height / fractol->width;
		fractol->factor_x = 2 * fractol->offset_x / fractol->width;
		fractol->factor_y = 2 * fractol->offset_y / fractol->height;
	}
	else
	{
		fractol->offset_x = AXIS_RANGE * fractol->width / fractol->height;
		fractol->offset_y = AXIS_RANGE;
		fractol->factor_x = 2 * fractol->offset_x / fractol->width;
		fractol->factor_y = 2 * fractol->offset_y / fractol->height;
	}
	fractol->c = assign(0, 0);
	fractol->z = assign(0, 0);
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
