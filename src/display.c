/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 11:20:43 by vgoncalv          #+#    #+#             */
/*   Updated: 2021/07/29 11:20:43 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static t_complex	translate(int x, int y, long double r, t_fractol *fractol)
{
	long double	tx;
	long double	ty;
	long double	factor;

	factor = (2 * r) / fractol->w_size;
	tx = (x * factor) - r;
	ty = (y * factor) - r;
	return (assign(tx, ty));
}

static int	create_pixelmap(t_fractol *fractol, long double radius)
{
	int	i;
	int	color;
	int	area;

	i = 0;
	area = fractol->w_size * fractol->w_size;
	while (i < area)
	{
		fractol->c = translate(i % fractol->w_size,
				i / fractol->w_size,
				radius,
				fractol);
		color = get_color(fractol->fractal(fractol));
		fractol->data[i] = color;
		i++;
	}
	return (0);
}

int	display_fractal(t_fractol *fractol, long double radius)
{
	int	i;
	int	area;

	create_pixelmap(fractol, radius);
	i = -1;
	area = fractol->w_size * fractol->w_size;
	while (++i < area)
		mlx_pixel_put(fractol->mlx,
			fractol->window, i % fractol->w_size,
			i / fractol->w_size,
			fractol->data[i]);
	return (0);
}
