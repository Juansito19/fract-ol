/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrosio <jbrosio@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 20:51:31 by jbrosio           #+#    #+#             */
/*   Updated: 2025/09/11 15:56:06 by jbrosio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	clean_and_exit(t_fractol *f)
{
	mlx_delete_image(f->mlx, f->img);
	mlx_delete_image(f->mlx, f->tmp_img);
	mlx_close_window(f->mlx);
	mlx_terminate(f->mlx);
	exit (0);
}

void	ft_put_fractal(t_fractol *f)
{
	if (f->fractal_type == 0)
		ft_calc_mandelbrot(f);
	else if (f->fractal_type == 1)
		ft_calc_julia(f);
}

void	print_examples(void)
{
	ft_printf("         > ./fractol julia -0.7 0.35462\n");
	ft_printf("         > ./fractol julia -0.4 -0.59\n");
	ft_printf("         > ./fractol julia 0.355534 -0.337292\n");
	ft_printf("         > ./fractol julia 0 0.8\n\n");
}

void	print_instructions(void)
{
	ft_printf("\n=========================\n");
	ft_printf("| FRACTOL PROGRAM USAGE |\n");
	ft_printf("=========================\n\n");
	ft_printf("Syntax:\n───────\n\n");
	ft_printf("    ./fractol <fractal name>\n\n");
	ft_printf("    ./fractol <fractal name> [parameters]\n\n");
	ft_printf("Availabel fractals:\n───────────────────\n\n");
	ft_printf("    - mandelbrot\n");
	ft_printf("       Example = ./fractol mandelbrot\n\n");
	ft_printf("    - julia\n");
	ft_printf("       Example = ./fractol julia [parameters]");
	ft_printf("       Example = ./fractol julia [parameters] [parameters]\n\n");
	ft_printf("Notes:\n──────\n\n");
	ft_printf("    - Use the mouse wheel to zoom in and out.\n");
	ft_printf("    - Use the arrow keys to move the views.\n");
	ft_printf("    - Press ESC to exit or press de [ x ] in the window.\n");
	ft_printf("    - For Julia, try different");
	ft_printf(" parameters for unique shapes.\n\n");
	print_examples();
	ft_printf("================================");
	ft_printf("==============================\n\n");
	exit(1);
}
