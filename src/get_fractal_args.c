/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_fractal_args.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgocalv <vgocalv@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 16:07:39 by vgocalv           #+#    #+#             */
/*   Updated: 2021/08/09 16:07:39 by vgocalv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	check_complex_d(char **opt)
{
	size_t	offset;

	offset = 0;
	while ((*opt)[offset] != '.'
		&& (*opt)[offset] != '+' && (*opt)[offset] != '-'
		&& (*opt)[offset] != 'i')
	{
		if (!ft_isdigit((*opt)[offset++]))
			return (1);
	}
	if ((*opt)[offset] == '.')
		offset++;
	while (ft_isdigit((*opt)[offset]))
		offset++;
	*opt += offset;
	return (0);
}

static int	check_complex(char *opt)
{
	char	*table;
	size_t	offset;

	table = "+d+di";
	offset = -1;
	while (table[++offset] != '\0')
	{
		if (table[offset] == '+')
		{
			if (*opt != '+' && *opt != '-' && !ft_isdigit(*opt))
				return (1);
			if (*opt == '+' || *opt == '-')
				opt++;
		}
		else if (table[offset] == 'd')
			check_complex_d(&opt);
		else if (table[offset] == 'i')
		{
			if (ft_strcmp("i", opt))
				return (1);
		}
	}
	return (0);
}

void	get_fractal_args(char *opt, t_fractol *fractol)
{
	char	*ptr;

	if (check_complex(opt))
		raise(INVALID_FRACTAL_OPTIONS, opt, fractol);
	ptr = ft_strrchr(opt + 1, '+');
	if (ptr == NULL)
		ptr = ft_strrchr(opt + 1, '-');
	if (ptr == NULL)
		raise(INVALID_FRACTAL_OPTIONS, opt, fractol);
	fractol->z.real = ft_atold(opt);
	fractol->z.complex = ft_atold(ptr);
}
