/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrosio <jbrosio@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 17:15:27 by jbrosio           #+#    #+#             */
/*   Updated: 2025/09/11 13:32:15 by jbrosio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

/*
0 para Mandelbrot, 1 para Julia
fractal_type = 0;  Inicializa como Mandelbrot

Parámetros Julia
real = -0.7 == Valor por defecto     asigna tras parsear
imaginary = 0.27015 == Valor por defecto  asigna tras parsear */

/* function that choose fractal type */
void	ft_init_fractal(t_fractol *fractal, char **av)
{
	if (!ft_strncmp(av[1], "mandelbrot", 11))
		fractal->fractal_type = 0;
	else if (!ft_strncmp(av[1], "julia", 6))
	{
		fractal->fractal_type = 1;
		fractal->real = ft_atod(av[2]);
		fractal->imaginary = ft_atod(av[3]);
	}
	if (!fractal->img_exist)
	{
		fractal->img_exist = 1;
		ft_put_fractal(fractal);
	}
}

void	ft_init_window(t_fractol *f)
{
	f->mlx = mlx_init(f->width, f->height, "Fractol", 1);
	if (!f->mlx)
		exit (EXIT_FAILURE);
	f->tmp_img = mlx_new_image(f->mlx, f->width, f->height);
	f->img = mlx_new_image(f->mlx, f->width, f->height);
	if (!f->img || !f->tmp_img)
	{
		mlx_delete_image(f->mlx, f->tmp_img);
		mlx_delete_image(f->mlx, f->img);
		mlx_close_window(f->mlx);
		mlx_terminate(f->mlx);
		exit (EXIT_FAILURE);
	}
}

void	ft_init_struct(t_fractol *fractal)
{
	fractal->width = WIDTH;
	fractal->height = HEIGHT;
	fractal->img_exist = 0;
	fractal->max_real = 2.0;
	fractal->min_real = -2.0;
	fractal->max_imag = 1.5;
	fractal->min_imag = -1.5;
	fractal->zoom = 1.0;
}

void	ft_start_program(t_fractol *fractal, char **av)
{
	ft_init_struct(fractal);
	ft_init_window(fractal);
	ft_init_fractal(fractal, av);
	ft_hooks(fractal);
	mlx_loop(fractal->mlx);
	mlx_delete_image(fractal->mlx, fractal->img);
	mlx_delete_image(fractal->mlx, fractal->tmp_img);
	mlx_close_window(fractal->mlx);
	mlx_terminate(fractal->mlx);
}

int	main(int ac, char **av)
{
	t_fractol	fractal;

	(void)ac;
	if (!ft_all_control(ac, av))
		ft_start_program(&fractal, av);
	else
		print_instructions();
	return (0);
}

/*
JULIA
 > -0.7 0.35462
 > -0.4 -0.59
 > 0.355534 -0.337292
 > 0 0.8
 > 0.37 0.1
*/