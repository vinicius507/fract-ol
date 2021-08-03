/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 15:44:29 by vgoncalv          #+#    #+#             */
/*   Updated: 2021/08/03 15:44:29 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom(int z, t_fractol *fractol)
{
	if (z > 0)
		fractol->scale -= ZOOM_STEP;
	else if (z < 0)
		fractol->scale += ZOOM_STEP;
	else
		fractol->scale = 1.0L;
	fractol->viewport = fractol->radius * fractol->scale;
	fractol->factor = (2 * fractol->viewport) / fractol->w_size;
}
