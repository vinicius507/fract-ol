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

static int	get_julia_options(char *opt, t_fractol *fractol)
{
	char	*ptr;

	if (!ft_isdigit(*opt))
		return (1);
	ptr = opt + ft_strlen(opt);
	if (*(ptr - 1) != 'i')
		return (1);
	ptr = ft_strchr(opt, '+');
	if (ptr == NULL || !ft_isdigit(*(ptr + 1)))
		return (1);
	fractol->z.real = ft_atold(opt);
	fractol->z.complex = ft_atold(ptr + 1);
	return (0);
}

static int	set_fractal(int *i, int argc, char **argv, t_fractol *fractol)
{
	if (fractol->fractal == NULL && !ft_strncmp(argv[*i], "Mandelbrot", 10))
		fractol->fractal = mandelbrot;
	else if (fractol->fractal == NULL && !ft_strncmp(argv[*i], "Julia", 5))
	{
		*i += 1;
		if (*i == argc)
			raise(NO_FRACTAL_OPTIONS, NULL, fractol);
		fractol->fractal = julia;
		if (get_julia_options(argv[*i], fractol))
			raise(INVALID_FRACTAL_OPTIONS, argv[*i], fractol);
	}
	else if (fractol->fractal == NULL && !ft_strncmp(argv[*i], "Mandelbar", 9))
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
		if (!ft_strncmp(argv[i], "--help", 6))
		{
			print_help(fractol->fractol);
			kill(fractol, 0);
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
