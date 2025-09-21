/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths_2_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrosio <jbrosio@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 21:40:08 by jbrosio           #+#    #+#             */
/*   Updated: 2025/09/11 16:21:38 by jbrosio          ###   ########.fr       */
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

void	print_examples_par(void)
{
	ft_printf("         > ./fractol_bonus julia -0.7 0.35462\n");
	ft_printf("         > ./fractol_bonus julia -0.4 -0.59\n");
	ft_printf("         > ./fractol_bonus julia 0.355534 -0.337292\n");
	ft_printf("         > ./fractol_bonus julia 0 0.8\n\n");
	ft_printf("         > ./fractol_bonus flower 4\n");
	ft_printf("         > ./fractol_bonus flower 9\n\n");
	ft_printf("         > ./fractol_bonus butterfly 4\n");
	ft_printf("         > ./fractol_bonus butterfly 3\n\n");
}
