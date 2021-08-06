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

static void	init_image(t_fractol *fractol)
{
	fractol->image = ft_calloc(1, sizeof(t_image));
	fractol->image->image = mlx_new_image(fractol->mlx,
			fractol->width,
			fractol->height);
	if (fractol->image->image == NULL)
		kill(fractol, MLX_IMAGE_ERROR);
	fractol->image->data = mlx_get_data_addr(fractol->image->image,
			&(fractol->image->bits_per_pixel),
			&(fractol->image->size_line),
			&(fractol->image->endian));
	if (fractol->image->data == NULL)
		kill(fractol, MLX_IMAGE_ERROR);
}

void	init(t_fractol *fractol)
{
	fractol->mlx = mlx_init();
	if (fractol->mlx == NULL)
		kill(fractol, MLX_INIT_ERROR);
	fractol->window = mlx_new_window(fractol->mlx,
			fractol->width,
			fractol->height,
			"Fractol");
	if (fractol->window == NULL)
		kill(fractol, MLX_WINDOW_ERROR);
	init_image(fractol);
	register_keys(fractol);
	display_fractal(fractol);
	mlx_loop(fractol->mlx);
}
