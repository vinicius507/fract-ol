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

// OPTIM: make it with a single loop
static int	create_pixelmap(t_fractol *fractol, long double radius)
{
	int	i;
	int	j;
	int	color;
	int	*data;

	i = 0;
	while (i <= fractol->w_size)
	{
		data = (int *)(fractol->image->data + (fractol->image->size_line * i));
		j = 0;
		while (j < fractol->w_size)
		{
			fractol->c = translate(j, i, radius, fractol);
			color = mlx_get_color_value(fractol->mlx,
					get_color(fractol->fractal(fractol)));
			data[j] = color;
			j++;
		}
		i++;
	}
	return (0);
}

int	display_fractal(t_fractol *fractol, long double radius)
{
	create_pixelmap(fractol, radius);
	mlx_put_image_to_window(fractol->mlx,
		fractol->window,
		fractol->image->image,
		0, 0);
	return (0);
}
