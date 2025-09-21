/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrosio <jbrosio@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 20:51:31 by jbrosio           #+#    #+#             */
/*   Updated: 2025/09/11 16:23:00 by jbrosio          ###   ########.fr       */
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

uint32_t	ft_put_color(t_fractol *f, int i, int iter)
{
	if (f->color == 1)
		return (ft_get_color_one(i, iter));
	else if (f->color == 2)
		return (ft_get_color_two(i, iter));
	else if (f->color == 3)
		return (ft_get_color_three(i, iter));
	else if (f->color == 4)
		return (ft_get_color_four(i, iter));
	else if (f->color == 5)
		return (ft_get_color_five(i, iter));
	return (0);
}

void	ft_put_fractal(t_fractol *f)
{
	if (f->fractal_type == 0)
		ft_calc_mandelbrot(f);
	else if (f->fractal_type == 1)
		ft_calc_julia(f);
	else if (f->fractal_type == 2)
		ft_calc_flower(f);
	else if (f->fractal_type == 3)
		ft_calc_butterfly(f);
}

void	print_examples(void)
{
	ft_printf("Availabel fractals:\n───────────────────\n\n");
	ft_printf("    - mandelbrot\n");
	ft_printf("       Example = ./fractol_bonus mandelbrot\n\n");
	ft_printf("    - julia\n");
	ft_printf("       Example = ./fractol_bonus julia");
	ft_printf(" [parameters] [parameters]\n\n");
	ft_printf("Fractals bonus:\n───────────────\n\n");
	ft_printf("    - butterfly\n");
	ft_printf("       Example = ./fractol_bonus butterfly [parameters]\n\n");
	ft_printf("    - flower\n");
	ft_printf("       Example = ./fractol_bonus flower [parameters]\n\n");
}

void	print_instructions(void)
{
	ft_printf("\n=========================\n");
	ft_printf("| FRACTOL PROGRAM USAGE |\n");
	ft_printf("=========================\n\n");
	ft_printf("Syntax:\n───────\n\n");
	ft_printf("    ./fractol_bonus <fractal name>\n\n");
	ft_printf("    ./fractol_bonus <fractal name> [parameters]\n\n");
	print_examples();
	ft_printf("Notes:\n──────\n");
	ft_printf("    - Use the mouse wheel to zoom in and out.\n");
	ft_printf("    - Use the arrow keys to move the views.\n");
	ft_printf("    - Press ESC to exit or press de [ x ] in the window.\n");
	ft_printf("    - For Julia, try different parameters for unique shapes.\n");
	ft_printf("    - For flower, try different ");
	ft_printf("parameters for unique shapes.\n");
	ft_printf("    - For butterfly, try different");
	ft_printf(" parameters for unique shapes.\n\n");
	print_examples_par();
	ft_printf("==============================");
	ft_printf("================================\n\n");
	exit(1);
}
