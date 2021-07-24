/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 22:05:46 by vgoncalv          #+#    #+#             */
/*   Updated: 2021/07/22 22:05:46 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "ft_complex.h"

int	main(int argc, char **argv)
{
	t_fractol	fractol;

	set_defaults(&fractol);
	argparse(argc, argv, &fractol);
	return (0);
}
