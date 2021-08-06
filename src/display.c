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

static int	create_pixelmap(t_fractol *fractol)
{
	int	i;
	int	x;
	int	y;
	int	color;
	int	*data;

	i = fractol->width * fractol->height;
	while (i--)
	{
		x = i % fractol->width;
		y = i / fractol->width;
		data = (int *)(fractol->image->data
				+ (fractol->image->size_line * y));
		fractol->c = translate(x, y, fractol);
		color = mlx_get_color_value(fractol->mlx,
				get_color(fractol->fractal(fractol)));
		data[x] = color;
	}
	return (0);
}

int	display_fractal(t_fractol *fractol)
{
	create_pixelmap(fractol);
	mlx_put_image_to_window(fractol->mlx,
		fractol->window,
		fractol->image->image,
		0, 0);
	return (0);
}
