/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argparse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 18:10:05 by vgoncalv          #+#    #+#             */
/*   Updated: 2021/07/23 18:10:05 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	set_fractal(char *arg, t_fractol *fractol)
{
	if (!ft_strncmp(arg, "Mandelbrot", 9))
		fractol->fractal = mandelbrot;
	else if (!ft_strncmp(arg, "Julia", 5))
		fractol->fractal = julia;
	else
		return (1);
	return (0);
}

void	argparse(int argc, char **argv, t_fractol *fractol)
{
	int		i;

	if (argc == 1)
		arg_error(argv[0], NULL, NO_ARG);
	i = 0;
	while (++i < argc)
	{
		if (!ft_strncmp(argv[i], "--help", 6))
		{
			print_help(argv[0]);
			exit(0);
		}
		else
		{
			if (fractol->fractal != NULL && set_fractal(argv[i], fractol))
				break ;
		}
	}
	if (i < argc)
		arg_error(argv[0], argv[i], UNKNOWN_ARG);
}
