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

void	zoom(int z, t_fractol *fractol, int mouse_x, int mouse_y)
{
	long double	zoom;
	t_complex	mouse;

	zoom = exp(ZOOM_STEP * -z);
	mouse = translate(mouse_x, mouse_y, fractol);
	fractol->offset_x += fractol->factor_x * mouse_x
		* (fractol->scale * zoom - fractol->scale);
	fractol->offset_y += fractol->factor_y * mouse_y
		* (fractol->scale * zoom - fractol->scale);
	fractol->scale *= zoom;
}
