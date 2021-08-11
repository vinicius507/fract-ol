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
		kill(fractol, EXIT_SUCCESS);
	else if (key == R_KEY)
		set_default_viewport(fractol);
	else if (key == W_KEY || key == UP_KEY)
		fractol->offset_y += 0.05L * fractol->scale;
	else if (key == A_KEY || key == LEFT_KEY)
		fractol->offset_x += 0.05L * fractol->scale;
	else if (key == S_KEY || key == DOWN_KEY)
		fractol->offset_y -= 0.05L * fractol->scale;
	else if (key == D_KEY || key == RIGHT_KEY)
		fractol->offset_x -= 0.05L * fractol->scale;
	display_fractal(fractol);
	return (0);
}

int	mouse_keys(int key, unsigned int px, unsigned int py, t_fractol *fractol)
{
	if (key == MWHEEL_UP)
		zoom(1, fractol, px, py);
	else if (key == MWHEEL_DOWN)
		zoom(-1, fractol, px, py);
	else if (fractol->fn == julia && key == MLEFT)
		fractol->z = translate(px, py, fractol);
	display_fractal(fractol);
	return (0);
}

void	register_keys(t_fractol *fractol)
{
	mlx_key_hook(fractol->window, keys, fractol);
	mlx_mouse_hook(fractol->window, mouse_keys, fractol);
}
