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
	int			i;

	c = fractol->c;
	i = 0;
	while (abs_squared(c) <= 4.0 && i++ < MAX_ITER)
	{
		c = multiply(c, c);
		c = add(c, fractol->z);
	}
	return (i);
}
