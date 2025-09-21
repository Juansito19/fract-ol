/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrosio <jbrosio@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 20:03:40 by jbrosio           #+#    #+#             */
/*   Updated: 2025/09/11 13:46:44 by jbrosio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

uint32_t	ft_get_color(int i, int iter)
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
		r = (uint8_t)(127 * (sin(6 * PI * t) + 1));
		g = (uint8_t)(127 * (sin(8 * PI * t + 2) + 1));
		b = (uint8_t)(127 * (cos(10 * PI * t + 1) + 1));
	}
	return (r << 30 | g << 16 | b << 8 | 0xFF);
}
