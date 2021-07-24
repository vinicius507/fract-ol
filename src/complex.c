/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 16:31:08 by vgoncalv          #+#    #+#             */
/*   Updated: 2021/07/23 16:31:08 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_complex.h"
#include <math.h>

inline t_complex	assign(long double real, long double complex)
{
	t_complex	res;

	res.real = real;
	res.complex = complex;
	return (res);
}

inline t_complex	add(t_complex z1, t_complex z2)
{
	t_complex	res;

	res.real = z1.real + z2.real;
	res.complex = z1.complex + z2.complex;
	return (res);
}

inline t_complex	multiply(t_complex z1, t_complex z2)
{
	t_complex	res;

	res.real = (z1.real * z2.real) - (z1.complex * z2.complex);
	res.complex = (z1.real * z2.complex) + (z1.complex * z2.real);
	return (res);
}

inline long double	abs_squared(t_complex z)
{
	return (pow(z.real, 2.0) + pow(z.complex, 2.0));
}
