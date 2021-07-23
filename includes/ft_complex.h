/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_complex.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 16:26:44 by vgoncalv          #+#    #+#             */
/*   Updated: 2021/07/23 16:26:44 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_COMPLEX_H
# define FT_COMPLEX_H

typedef struct s_complex
{
	long double	real;
	long double	complex;
}	t_complex;

/* Assigns value to a `t_complex` number */
t_complex	assign(long double real, long double complex);

/* Adds two `t_complex` numbers */
t_complex	add(t_complex z1, t_complex z2);

/* Multiplies two `t_complex` numbers */
t_complex	multiply(t_complex z1, t_complex z2);

/* Gets the module of a `t_complex` number */
long double	module(t_complex z);

#endif
