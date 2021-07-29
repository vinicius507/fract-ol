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

int	keys(int key, void *f_ptr)
{
	t_fractol	*fractol;

	fractol = (t_fractol *)f_ptr;
	if (key == ESC_KEY || key == Q_KEY)
	{
		mlx_destroy_window(fractol->mlx, fractol->window);
		exit(0);
	}
	else
		printf("Key Value: %d\n", key);
	return (0);
}

int	mouse_keys(int key, void *f_ptr)
{
	t_fractol	*fractol;

	fractol = (t_fractol *)f_ptr;
	printf("Mouse Key Value: %d\n", key);
	return (0);
}

void	register_keys(t_fractol *fractol)
{
	mlx_key_hook(fractol->window, keys, (void *)fractol);
	mlx_mouse_hook(fractol->window, mouse_keys, (void *)fractol);
}
