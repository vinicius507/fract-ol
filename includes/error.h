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
	UNKNOWN_ARG,
	NO_ARG,
}	t_error;

void	arg_error(const char *fractol, const char *argument, t_error code);

#endif
