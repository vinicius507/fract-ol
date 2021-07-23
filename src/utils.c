/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 18:04:30 by vgoncalv          #+#    #+#             */
/*   Updated: 2021/07/23 18:04:30 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	print_help(const char *fractol)
{
	printf("Usage: %s [FRACTAL]\n\n"
		"Fractal options are: Mandelbrot, Julia\n", fractol);
}
