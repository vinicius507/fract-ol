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

	r_temp = ((r + m) * 0xff);
	g_temp = ((g + m) * 0xff);
	b_temp = ((b + m) * 0xff);
	return (r_temp << 16 | g_temp << 8 | b_temp);
}

static int	hsv2rgb(int h, int s, int v)
{
	int	c;
	int	x;
	int	m;
	int	rgb;

	c = v * s;
	x = c * (1 - abs(((h / 60) % 2) - 1));
	m = v - c;
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

// TODO: change how to display colors
int	get_color(int iteration)
{
	int	h;
	int	s;
	int	v;
	int	argb;

	h = iteration * 360 / MAX_ITER;
	s = 1;
	if (iteration == MAX_ITER)
		v = 0;
	else
		v = 1;
	argb = hsv2rgb(h, s, v) | (0xff << 24);
	return (argb);
}
