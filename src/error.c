/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 18:40:57 by vgoncalv          #+#    #+#             */
/*   Updated: 2021/07/23 18:40:57 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	arg_error(const char *fractol, const char *argument, t_error code)
{
	if (code == UNKNOWN_ARG)
		printf("%s: unknown argument '%s'\n", fractol, argument);
	else if (code == NO_ARG)
		printf("%s: no argument given\n", fractol);
	print_help(fractol);
	exit(code);
}
