/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrosio <jbrosio@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 21:40:08 by jbrosio           #+#    #+#             */
/*   Updated: 2025/09/11 15:54:04 by jbrosio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

t_c	ft_sqrt_cmplx(t_c a)
{
	t_c	res;

	res.real = (a.real * a.real) - (a.img * a.img);
	res.img = 2 * a.real * a.img;
	return (res);
}

t_c	ft_z_cmplx(t_c a)
{
	t_c	res;

	res.real = (a.real * a.real) - (a.img * a.img);
	res.img = a.real * a.img;
	return (res);
}

double	ft_module_cmplx(t_c n)
{
	return (sqrt((n.real * n.real) + (n.img * n.img)));
}
