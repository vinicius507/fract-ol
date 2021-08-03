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
	long double	r2;
	long double	i2;
	int			i;

	z = assign(0, 0);
	r2 = 0;
	i2 = 0;
	i = 0;
	while (r2 + i2 <= 4.0 && i < MAX_ITER)
	{
		z.complex = 2 * z.real * z.complex + fractol->c.complex;
		z.real = r2 - i2 + fractol->c.real;
		r2 = z.real * z.real;
		i2 = z.complex * z.complex;
		i++;
	}
	return (i);
}
