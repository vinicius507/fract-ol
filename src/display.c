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

// TODO: implement zoom
static t_complex	translate(int x, int y, t_fractol *fractol)
{
	long double			tx;
	long double			ty;
	static long double	old_scale;

	if (!old_scale)
		old_scale = 1.0L;
	tx = (x * fractol->factor) - fractol->viewport + fractol->offset_x;
	ty = (y * fractol->factor) - fractol->viewport + fractol->offset_y;
	return (assign(tx, ty));
}

static int	create_pixelmap(t_fractol *fractol)
{
	int	i;
	int	x;
	int	y;
	int	color;
	int	*data;

	i = fractol->w_size * fractol->w_size;
	while (i--)
	{
		x = i % fractol->w_size;
		y = i / fractol->w_size;
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
