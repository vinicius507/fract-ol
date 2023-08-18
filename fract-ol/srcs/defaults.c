/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defaults.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgocalv <vgocalv@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 10:55:45 by vgocalv           #+#    #+#             */
/*   Updated: 2021/08/06 10:55:45 by vgocalv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	set_default_viewport(t_fractol *fractol)
{
	fractol->scale = 1.0L;
	if (fractol->width <= fractol->height)
	{
		fractol->offset_x = AXIS_RANGE;
		fractol->offset_y = AXIS_RANGE * fractol->height / fractol->width;
		fractol->factor_x = (2 * fractol->offset_x / fractol->width);
		fractol->factor_y = 2 * fractol->offset_y / fractol->height;
	}
	else
	{
		fractol->offset_x = AXIS_RANGE * fractol->width / fractol->height;
		fractol->offset_y = AXIS_RANGE;
		fractol->factor_x = 2 * fractol->offset_x / fractol->width;
		fractol->factor_y = 2 * fractol->offset_y / fractol->height;
	}
}

void	set_defaults(t_fractol *fractol)
{
	fractol->fractol = "fractol";
	fractol->fn = NULL;
	fractol->mlx = NULL;
	fractol->window = NULL;
	fractol->image = NULL;
	fractol->width = 1200;
	fractol->height = 600;
	set_default_viewport(fractol);
	fractol->c = assign(0, 0);
	fractol->z = assign(0, 0);
}
