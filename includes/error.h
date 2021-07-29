/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 19:02:13 by vgoncalv          #+#    #+#             */
/*   Updated: 2021/07/23 19:02:13 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

/* Exit Codes for `fractol` */
typedef enum e_error
{
	UNKNOWN_ARG	= 1<<0,
	NO_ARG = 1<<1,
	NO_FRACTAL_OPTIONS = 1<<2,
	INVALID_FRACTAL_OPTIONS = 1<<3,
	SYS_ERROR = 1<<4,
}	t_error;

void	raise(t_error code, const char *argument, const char *fractol);

#endif
