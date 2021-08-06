/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgocalv <vgocalv@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 10:41:05 by vgocalv           #+#    #+#             */
/*   Updated: 2021/08/06 10:41:05 by vgocalv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex	translate(int x, int y, t_fractol *fractol)
{
	long double			tx;
	long double			ty;

	tx = (x * fractol->factor_x * fractol->scale) - fractol->offset_x;
	ty = (y * fractol->factor_y * fractol->scale) - fractol->offset_y;
	return (assign(tx, -ty));
}
