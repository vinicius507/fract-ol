/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbar.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgocalv <vgocalv@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 17:05:39 by vgocalv           #+#    #+#             */
/*   Updated: 2021/08/08 17:05:39 by vgocalv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mandelbar(t_fractol *fractol)
{
	t_complex	p;
	long double	r2;
	long double	i2;
	long double	temp;
	int			i;

	p.real = fractol->c.real;
	p.complex = fractol->c.complex;
	r2 = fractol->c.real * fractol->c.real;
	i2 = fractol->c.complex * fractol->c.complex;
	i = 0;
	while (r2 + i2 <= 4.0 && i < MAX_ITER)
	{
		temp = r2 - i2 + p.real;
		fractol->c.complex = -2 * fractol->c.real
			* fractol->c.complex + p.complex;
		fractol->c.real = temp;
		r2 = fractol->c.real * fractol->c.real;
		i2 = fractol->c.complex * fractol->c.complex;
		i++;
	}
	return (i);
}
