/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrosio <jbrosio@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 20:03:40 by jbrosio           #+#    #+#             */
/*   Updated: 2025/09/11 17:24:47 by jbrosio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

uint32_t	ft_get_color_one(int i, int iter)
{
	uint8_t	r;
	uint8_t	g;
	uint8_t	b;
	double	t;

	if (i == iter)
		return (0x00002033);
	else if (i == 1)
		return (DARK_BLUE);
	else if (i <= 3)
		return (NEON_BLUE);
	else if (i <= 5)
		return (0x00009033);
	else if (i <= 9)
		return (BLUE);
	else
	{
		t = (double)(i - 1) / iter;
		r = (uint8_t)(127 * (sin(6 * PI * t) + 1));
		g = (uint8_t)(127 * (sin(8 * PI * t + 2) + 1));
		b = (uint8_t)(127 * (cos(10 * PI * t + 1) + 1));
	}
	return (r << 30 | g << 16 | b << 8 | 0xFF);
}

uint32_t	ft_get_color_two(int i, int iter)
{
	uint8_t	r;
	uint8_t	g;
	uint8_t	b;
	double	t;

	if (i == iter)
		return (0x00002033);
	else
	{
		t = (double)(i - 1) / iter;
		r = (uint8_t)(127 * (sin(16 * PI * t) + 1));
		g = (uint8_t)(127 * (sin(28 * PI * t + 2) + 1));
		b = (uint8_t)(127 * (cos(30 * PI * t + 1) + 1));
	}
	return (r << 24 | g << 16 | b << 8 | 0xFF);
}

uint32_t	ft_get_color_three(int i, int iter)
{
	uint8_t	r;
	uint8_t	g;
	uint8_t	b;
	double	t;

	if (i == iter)
		return (0x00002033);
	else
	{
		t = (double)(i - 1) / iter;
		r = (uint8_t)(127 * (sin(6 * PI * t) + 100));
		g = (uint8_t)(127 * (sin(8 * PI * t + 2) + 200));
		b = (uint8_t)(127 * (cos(10 * PI * t + 1) + 500));
	}
	return (r << 24 | g << 16 | b << 8 | 0xFF);
}

uint32_t	ft_get_color_four(int i, int iter)
{
	uint8_t	r;
	uint8_t	g;
	uint8_t	b;
	double	t;

	if (i == iter)
		return (0x00002033);
	else
	{
		t = (double)(i - 50) / iter;
		r = (uint8_t)(127 * (sin(6 * PI * t) + 1));
		g = (uint8_t)(127 * (sin(8 * PI * t + 2) + 1));
		b = (uint8_t)(127 * (cos(10 * PI * t + 1) + 1));
	}
	return (r << 24 | g << 16 | b << 8 | 0xFF);
}

uint32_t	ft_get_color_five(int i, int iter)
{
	uint8_t	r;
	uint8_t	g;
	uint8_t	b;
	double	t;

	if (i == iter)
		return (0x00002033);
	else
	{
		t = (double)(i - 1) / iter;
		r = (uint8_t)(127 * (sin(17 * PI * t) + 1));
		g = (uint8_t)(127 * (sin(20 * PI * t + 2) + 1));
		b = (uint8_t)(127 * (cos(32 * PI * t + 1) + 1));
	}
	return (r << 24 | g << 16 | b << 8 | 0xFF);
}
