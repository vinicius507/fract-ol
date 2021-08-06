/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 09:45:04 by vgoncalv          #+#    #+#             */
/*   Updated: 2021/07/29 09:45:04 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "fractol_keys.h"

int	keys(int key, t_fractol *fractol)
{
	if (key == ESC_KEY || key == Q_KEY)
	{
		mlx_destroy_window(fractol->mlx, fractol->window);
		kill(fractol, 0);
	}
	else if (key == R_KEY)
	{
		set_default_viewport(fractol);
		display_fractal(fractol);
	}
	else
		printf("Key Value: %d\n", key);
	return (0);
}

int	mouse_keys(int key, unsigned int px, unsigned int py, t_fractol *fractol)
{
	if (key == MWHEEL_UP)
	{
		zoom(1, fractol, px, py);
		display_fractal(fractol);
	}
	else if (key == MWHEEL_DOWN)
	{
		zoom(-1, fractol, px, py);
		display_fractal(fractol);
	}
	else
		printf("%d: %Lf %d: %Lf\n",
			px,
			px * fractol->factor_x - fractol->offset_x,
			py,
			-(py * fractol->factor_y - fractol->offset_y));
	return (0);
}

void	register_keys(t_fractol *fractol)
{
	mlx_key_hook(fractol->window, keys, fractol);
	mlx_mouse_hook(fractol->window, mouse_keys, fractol);
}
