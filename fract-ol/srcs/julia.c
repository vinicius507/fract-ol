/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 11:56:48 by vgoncalv          #+#    #+#             */
/*   Updated: 2021/07/24 11:56:48 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	julia(t_fractol *fractol)
{
	t_complex	c;
	t_complex	z;
	long double	r2;
	long double	i2;
	int			i;

	z = fractol->z;
	c = fractol->c;
	r2 = fractol->c.real * fractol->c.real;
	i2 = fractol->c.complex * fractol->c.complex;
	i = 0;
	while (r2 + i2 <= 4.0 && i < MAX_ITER)
	{
		c.complex = 2 * c.real * c.complex + z.complex;
		c.real = r2 - i2 + z.real;
		r2 = c.real * c.real;
		i2 = c.complex * c.complex;
		i++;
	}
	return (i);
}
