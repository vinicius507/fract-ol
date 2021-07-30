/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 11:22:43 by vgoncalv          #+#    #+#             */
/*   Updated: 2021/07/29 11:22:43 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	get_rgb(int r, int g, int b, int m)
{
	int	r_temp;
	int	g_temp;
	int	b_temp;

	r_temp = r * m;
	g_temp = g * m;
	b_temp = b * m;
	return (r_temp << 16 | g_temp << 8 | b_temp);
}

static int	hsl2rgb(int h, int s, int l)
{
	int	c;
	int	x;
	int	m;
	int	rgb;

	c = 1 - abs((2 * l) - 1) * s;
	x = c * (1 - abs(((h / 60) % 2) - 1));
	m = l - (c / 2);
	if (0 <= h && h < 60)
		rgb = get_rgb(c, x, 0, m);
	else if (60 <= h && h < 120)
		rgb = get_rgb(x, c, 0, m);
	else if (120 <= h && h < 180)
		rgb = get_rgb(0, c, x, m);
	else if (180 <= h && h < 240)
		rgb = get_rgb(0, x, c, m);
	else if (240 <= h && h < 300)
		rgb = get_rgb(x, 0, c, m);
	else
		rgb = get_rgb(c, 0, x, m);
	return (rgb);
}

int	get_color(int iteration)
{
	int	h;
	int	s;
	int	l;
	int	argb;

	h = iteration * 360 / MAX_ITER;
	s = 100;
	if (iteration == MAX_ITER)
		l = 0;
	else
		l = 100;
	argb = 0xff << 24 | hsl2rgb(h, s, l);
	return (argb);
}
