/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 16:17:43 by vgoncalv          #+#    #+#             */
/*   Updated: 2021/07/23 16:17:43 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <math.h>

int	mandelbrot(t_fractol *fractol)
{
	t_complex	z;
	int			i;

	z = assign(0, 0);
	i = 0;
	while (abs_squared(z) <= 4.0 && i < MAX_ITER)
	{
		z = multiply(z, z);
		z = add(z, fractol->c);
		i++;
	}
	return (i);
}
