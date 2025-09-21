/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrosio <jbrosio@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 16:03:29 by jbrosio           #+#    #+#             */
/*   Updated: 2025/09/11 13:49:22 by jbrosio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	ft_hooks(t_fractol *f)
{
	mlx_key_hook(f->mlx, &ft_key_hook, f);
	mlx_resize_hook(f->mlx, &ft_resize_hook, f);
	mlx_scroll_hook(f->mlx, &ft_scroll_hook, f);
}

void	ft_key_hook(mlx_key_data_t keydata, void *param)
{
	t_fractol	*f;

	f = (t_fractol *)param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		clean_and_exit(f);
	if (keydata.key == MLX_KEY_R && keydata.action == MLX_PRESS)
	{
		f->zoom = 1.0;
		f->max_imag = 1.5;
		f->min_imag = -1.5;
		f->max_real = 2.0;
		f->min_real = -2.0;
		f->img_exist = 0;
		ft_put_fractal(f);
	}
}

void	ft_scroll_hook(double xdelta, double ydelta, void *param)
{
	t_fractol	*f;
	double		r_center;
	double		i_center;
	double		r_half_center;
	double		i_half_center;

	(void)xdelta;
	f = (t_fractol *)param;
	f->zoom = 1.0;
	if (ydelta < 0)
		f->zoom *= 1.03;
	else
		f->zoom *= 0.97;
	r_center = (f->max_real + f->min_real) / 2.0;
	i_center = (f->max_imag + f->min_imag) / 2.0;
	r_half_center = (f->max_real - f->min_real) / 2.0 * f->zoom;
	i_half_center = (f->max_imag - f->min_imag) / 2.0 * f->zoom;
	f->max_real = r_center + r_half_center;
	f->min_real = r_center - r_half_center;
	f->max_imag = i_center + i_half_center;
	f->min_imag = i_center - i_half_center;
	ft_put_fractal(f);
}

void	ft_resize_hook(int32_t new_width, int32_t new_height, void *param)
{
	t_fractol	*f;

	f = (t_fractol *)param;
	f->width = new_width;
	f->height = new_height;
	if (f->img)
		mlx_delete_image(f->mlx, f->img);
	f->img = mlx_new_image(f->mlx, f->width, f->height);
	ft_put_fractal(f);
}

void	ft_init_t_c(t_c *x)
{
	x->img = 0.0;
	x->real = 0.0;
}
