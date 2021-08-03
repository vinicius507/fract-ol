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

int	get_color(int iteration)
{
	int		argb;
	double	factor;

	if (iteration == MAX_ITER)
		return (0xff000000);
	factor = (double)iteration / MAX_ITER;
	argb = 0xff << 24;
	argb |= (int)(9 * pow((1 - factor), 3) * factor * 255);
	argb |= (int)(6 * (1 - factor) * (int)pow(factor, 2) * 255) << 8;
	argb |= (int)(0.5 * pow((2 - factor), 3) * factor * 255) << 16;
	return (argb);
}
