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

static int	set_fractal(int *i, int argc, char **argv, t_fractol *fractol)
{
	if (fractol->fractal == NULL && !ft_strcmp(argv[*i], "Mandelbrot"))
		fractol->fractal = mandelbrot;
	else if (fractol->fractal == NULL && !ft_strcmp(argv[*i], "Julia"))
	{
		*i += 1;
		if (*i == argc)
			raise(NO_FRACTAL_OPTIONS, NULL, fractol);
		fractol->fractal = julia;
		get_fractal_args(argv[*i], fractol);
	}
	else if (fractol->fractal == NULL && !ft_strcmp(argv[*i], "Mandelbar"))
		fractol->fractal = mandelbar;
	if (fractol->fractal == NULL)
		return (1);
	return (0);
}

void	argparse(int argc, char **argv, t_fractol *fractol)
{
	int		i;

	fractol->fractol = argv[0];
	if (argc == 1)
		raise(NO_ARG, NULL, fractol);
	i = 0;
	while (++i < argc)
	{
		if (!ft_strcmp(argv[i], "--help"))
		{
			print_help(fractol->fractol);
			kill(fractol, EXIT_SUCCESS);
		}
		else
		{
			if (set_fractal(&i, argc, argv, fractol))
				break ;
		}
	}
	if (i < argc)
		raise(UNKNOWN_ARG, argv[i], fractol);
}
