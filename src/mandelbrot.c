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
#include <stdio.h>

#define MAX_ITER 80

int	mandelbrot(t_complex c)
{
	t_complex	z;
	int			i;

	z = assign(0, 0);
	i = 0;
	while (module(z) < 2.0 && i++ < MAX_ITER)
	{
		z = multiply(z, z);
		z = add(z, c);
	}
	return (i);
}
