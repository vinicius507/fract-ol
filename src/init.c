/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 18:43:27 by vgoncalv          #+#    #+#             */
/*   Updated: 2021/07/23 18:43:27 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init(t_fractol *fractol)
{
	fractol->mlx = mlx_init();
	fractol->window = mlx_new_window(fractol->mlx,
			fractol->w_size,
			fractol->w_size,
			"Fractol");
	register_keys(fractol);
	display_fractal(fractol, 2.0L);
	mlx_loop(fractol->mlx);
}
