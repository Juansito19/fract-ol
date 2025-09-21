/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrosio <jbrosio@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 19:13:06 by jbrosio           #+#    #+#             */
/*   Updated: 2025/09/11 15:52:20 by jbrosio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

t_c	ft_sum_cmplx(t_c a, t_c b)
{
	t_c	res;

	res.real = a.real + b.real;
	res.img = a.img + b.img;
	return (res);
}

t_c	ft_minus_cmplx(t_c a, t_c b)
{
	t_c	res;

	res.real = a.real - b.real;
	res.img = a.img - b.img;
	return (res);
}

t_c	ft_mult_cmplx(t_c z1, t_c z2)
{
	t_c	res;

	res.real = z1.real * z2.real - z1.img * z2.img;
	res.img = z1.real * z2.img + z1.img * z2.real;
	return (res);
}

t_c	ft_pow_cmplx(t_c z, int n)
{
	t_c	res;
	int	i;

	i = 1;
	res = z;
	while (i < n)
	{
		res = ft_mult_cmplx(res, z);
		i++;
	}
	return (res);
}
