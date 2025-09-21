/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrosio <jbrosio@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 15:41:26 by jbrosio           #+#    #+#             */
/*   Updated: 2025/09/11 16:52:17 by jbrosio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	ft_diverge_j(t_c z, t_c c)
{
	int		i;

	i = 0;
	while (i < ITER)
	{
		z = ft_sum_cmplx(ft_sqrt_cmplx(z), c);
		if (ft_module_cmplx(z) > 2)
			return (i);
		i++;
	}
	return (i);
}

void	ft_asign_julia(t_fractol *f, t_c *z, t_c *julia)
{
	ft_init_t_c(z);
	ft_init_t_c(julia);
	f->start_r = ((f->max_real - f->min_real) / f->width) * f->zoom;
	f->start_i = ((f->max_imag - f->min_imag) / f->height) * f->zoom;
	f->end_r = f->min_real * f->zoom;
	f->end_i = f->min_imag * f->zoom;
	z->img = f->imaginary;
	z->real = f->real;
	julia->img = f->imaginary;
	julia->real = f->real;
}

// f->real = (min_real + x * ((max_real - min_real) / width)) * zoom;
// f->imaginary = (min_imag + y	* ((max_imag - min_imag) / height)) * zoom;

void	ft_calc_julia(t_fractol *f)
{
	t_c			z;
	t_c			julia;
	int			x;
	int			y;
	int			i;

	x = -1;
	i = 0;
	ft_asign_julia(f, &z, &julia);
	while (++x < f->width)
	{
		y = 0;
		while (y < f->height)
		{
			julia.real = f->end_r + (x * f->start_r);
			julia.img = f->end_i + (y * f->start_i);
			i = ft_diverge_j(julia, z);
			f->color_draw = ft_put_color(f, i, ITER);
			mlx_put_pixel(f->tmp_img, x, y, f->color_draw);
			y++;
		}
	}
	f->img = f->tmp_img;
	mlx_image_to_window(f->mlx, f->img, 0, 0);
}
