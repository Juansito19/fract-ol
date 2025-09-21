/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrosio <jbrosio@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 17:15:41 by jbrosio           #+#    #+#             */
/*   Updated: 2025/09/11 17:35:28 by jbrosio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/libft.h"
# include "MLX42.h"
# include <math.h>

/*=========== colors ===========*/
# define BLACK 0x000000FF
# define WHITE 0xFFFFFFFf
# define RED 0xFF0000FF
# define GREEN 0x00FF00FF
# define BLUE 0x0000FFFF
# define YELLOW 0xFFFF00FF
# define CYAN 0x00FFFFFF
# define MAGENTA 0xFF00FFFF
# define PASTEL_BLUE 0x77AADDFf
# define PASTEL_GREEN 0x99FF99FF
# define PASTEL_RED 0xFFB3BAFF
# define PASTEL_LILA 0xD1B3FFFF
# define PASTEL_YELLOW 0xFFFFB3FF
# define BROWN 0x8B4513FF
# define OLIVE 0x808000FF
# define BEIGE 0xF5F5DCFF
# define LIGHT_GRAY 0xD3D3D3FF
# define ORANGE 0xFFA500FF
# define NEON_GREEN 0x39FF14FF
# define NEON_PINK 0xFF6EC7FF
# define NEON_BLUE 0x1B03A3FF
# define NEON_YELLOW 0xFFFF33FF
# define NEON_ORANGE 0xFF5E13FF
# define DARK_RED 0x8B0000FF
# define DARK_GREEN 0x006400FF
# define DARK_BLUE 0x00008BFF
# define LIGHT_RED 0xFFA07AFF
# define LIGHT_GREEN 0x90EE90FF
# define LIGHT_BLUE 0xADD8E6FF
# define VIOLET 0x8F00FFFF
# define INDIGO 0x4B0082FF
# define GOLD 0xFFD700FF
# define SILVER 0xC0C0C0FF
# define SALMON 0xFA8072FF
# define TOMATO 0xFF6347FF
# define CORAL 0xFF7F50FF
# define AQUA 0x00FFFFFF
# define TEAL 0x008080FF
# define NAVY 0x000080FF
# define MAROON 0x800000FF
# define OLIVE_DRAB 0x6B8E23FF
# define FOREST_GREEN 0x228B22FF
# define LIME 0x32CD32FF
# define CHARTREUSE 0x7FFF00FF
# define SPRING_GREEN 0x00FF7FFF
# define TURQUOISE 0x40E0D0FF
# define SKY_BLUE 0x87CEEBFF
# define DEEP_PINK 0xFF1493FF
# define HOT_PINK 0xFF69B4FF
# define LAVENDER 0xE6E6FAFF
# define MINT 0x98FF98FF
# define PEACH 0xFFE5B4FF
# define SAND 0xF4A460FF
/* ============================== */
# define ITER 60
# define PI 3.141592653589793
# define WIDTH 1920
# define HEIGHT 1080

typedef struct s_fractol
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	mlx_image_t	*tmp_img;
	int			img_exist;
	int			width;
	int			height;
	double		zoom;
	double		max_real;
	double		min_real;
	double		max_imag;
	double		min_imag;
	double		start_r;
	double		start_i;
	double		end_r;
	double		end_i;
	int			pwd;
	int			fractal_type;
	uint32_t	color_draw;
	int			color;
	double		real;
	double		imaginary;
}	t_fractol;

typedef struct s_c
{
	double		img;
	double		real;
}	t_c;

int			main(int ac, char **av);
void		ft_init_fractal(t_fractol *fractal, char **av);

/* ============================ */
/* 		  PARSING ERROS   		*/
int			ft_minus_plus_control(char *av);
int			ft_numbers_control(char *av, char error);
int			ft_name_ac_control(int ac, char **av);
int			ft_all_control(int ac, char **av);
int			ft_max_min_control(char *av);
/* ============================ */
/* ============================ */
/* 		  	  UTILS  	   		*/
uint32_t	ft_put_color(t_fractol *f, int i, int iter);
void		print_instructions(void);
void		ft_put_fractal(t_fractol *f);
void		clean_and_exit(t_fractol *f);
void		ft_init_t_c(t_c *x);
/* ============================ */
/* ============================ */
/* 		  	  COLOR  	   		*/
uint32_t	ft_get_color(int i, int iter);
uint32_t	ft_get_color_one(int i, int iter);
uint32_t	ft_get_color_two(int i, int iter);
uint32_t	ft_get_color_three(int i, int iter);
uint32_t	ft_get_color_four(int i, int iter);
uint32_t	ft_get_color_five(int i, int iter);
/* ============================ */
/* ============================ */
/* 		  	  HOOKS  	   		*/
void		ft_hooks(t_fractol *f);
void		ft_key_hook(mlx_key_data_t keydata, void *param);
void		ft_resize_hook(int32_t new_width, int32_t new_height, void *param);
void		ft_scroll_hook(double xdelta, double ydelta, void *param);
void		print_examples_par(void);
/* ============================ */
/* ============================ */
/* 		  	  MATHS  	   		*/
t_c			ft_mult_cmplx(t_c z1, t_c z2);
t_c			ft_pow_cmplx(t_c z, int n);
t_c			ft_sum_cmplx(t_c a, t_c b);
t_c			ft_minus_cmplx(t_c a, t_c b);
t_c			ft_sqrt_cmplx(t_c a);
t_c			ft_z_cmplx(t_c a);
double		ft_module_cmplx(t_c n);
/* ============================ */
/* ============================ */
/* 		  	  FRACTALS 	   		*/
void		ft_asign(t_fractol *f);
void		ft_calc_mandelbrot(t_fractol *screen_pos);
void		ft_calc_julia(t_fractol *fractal);
void		ft_calc_flower(t_fractol *f);
void		ft_calc_butterfly(t_fractol *f);
/* ============================ */

#endif 