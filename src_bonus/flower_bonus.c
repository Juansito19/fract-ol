/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flower_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrosio <jbrosio@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 22:52:47 by jbrosio           #+#    #+#             */
/*   Updated: 2025/09/11 16:12:53 by jbrosio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	ft_diverge_f(t_fractol *x)
{
	t_c		z;
	t_c		c;
	t_c		pwd;
	t_c		sum;
	int		i;

	i = 0;
	c.img = x->imaginary;
	c.real = x->real;
	z.img = 0.0;
	z.real = 0.0;
	while (i < ITER)
	{
		pwd = ft_pow_cmplx(z, x->pwd);
		sum = ft_sum_cmplx(pwd, z);
		z = ft_sum_cmplx(sum, c);
		if (ft_module_cmplx(z) > 4)
			return (i);
		i++;
	}
	return (i);
}

// f->real = (min_real + x * ((max_real - min_real) / width)) * zoom;
// f->imaginary = (min_imag + y	* ((max_imag - min_imag) / height)) * zoom;

void	ft_calc_flower(t_fractol *f)
{
	uint32_t	color;
	int			x;
	int			y;
	int			i;

	ft_asign(f);
	x = -1;
	i = 0;
	while (++x < f->width)
	{
		y = 0;
		while (y < f->height)
		{
			f->real = f->end_r + (x * f->start_r);
			f->imaginary = f->end_i + (y * f->start_i);
			i = ft_diverge_f(f);
			color = ft_put_color(f, i, ITER);
			mlx_put_pixel(f->tmp_img, x, y, color);
			y++;
		}
	}
	f->img = f->tmp_img;
	mlx_image_to_window(f->mlx, f->img, 0, 0);
}
