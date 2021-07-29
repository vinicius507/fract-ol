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

static void	arg_error_msg(t_error code, const char *arg, const char *fractol)
{
	if (code == UNKNOWN_ARG)
		printf("%s: unknown argument '%s'\n", fractol, arg);
	else if (code == NO_ARG)
		printf("%s: no argument given\n", fractol);
	else if (code == NO_FRACTAL_OPTIONS)
		printf("%s: no options passed to fractal(1 required)\n", fractol);
	else if (code == INVALID_FRACTAL_OPTIONS)
		printf("%s: invalid option passed to fractal '%s'\n", fractol, arg);
}

void	raise(t_error code, const char *arg, const char *fractol)
{
	if (code
		& (UNKNOWN_ARG | NO_ARG | NO_FRACTAL_OPTIONS | INVALID_FRACTAL_OPTIONS))
		arg_error_msg(code, arg, fractol);
	print_help(fractol);
	exit(code);
}
