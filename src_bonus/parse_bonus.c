/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrosio <jbrosio@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 20:01:35 by jbrosio           #+#    #+#             */
/*   Updated: 2025/09/07 22:28:08 by jbrosio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	ft_max_min_control(char *av)
{
	if (ft_atol(av) > INT_MAX)
		return (1);
	else if (ft_atol(av) < INT_MIN)
		return (1);
	return (0);
}

int	ft_minus_plus_control(char *av)
{
	int	i;
	int	minus;
	int	plus;

	i = 0;
	minus = 0;
	plus = 0;
	while (av[i])
	{
		if (av[i] == '-')
			minus++;
		if (av[i] == '+')
			plus++;
		if (i > 0 && (av[i] < 48 || av[i] > 57) && av[i] != 46)
			return (1);
		i++;
	}
	if (plus > 1 || minus > 1)
		return (1);
	return (0);
}

int	ft_numbers_control(char *av, char error)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	if (ft_minus_plus_control(av))
		return (1);
	while (av[i] && count < 2)
	{
		if (av[i] == error)
			count++;
		if (!ft_isdigit(av[i]))
			return (1);
		i++;
	}
	if (count > 1)
		return (1);
	else
		return (0);
}

int	ft_name_ac_control(int ac, char **av)
{
	if (ac == 2)
	{
		if (!ft_strncmp(av[1], "mandelbrot", 11))
			return (0);
		return (1);
	}
	else if (ac == 3)
	{
		if (!ft_strncmp(av[1], "flower", 7))
			return (0);
		else if (!ft_strncmp(av[1], "butterfly", 10))
			return (0);
		return (1);
	}
	else if (ac == 4)
	{
		if (!ft_strncmp(av[1], "julia", 6))
			return (0);
		return (1);
	}
	else
		return (1);
}

int	ft_all_control(int ac, char **av)
{
	if (ft_name_ac_control(ac, av))
		return (1);
	else if (ac == 3)
	{
		if (ft_numbers_control(av[2], '.'))
			return (1);
		if (ft_max_min_control(av[2]))
			return (1);
	}
	else if (ac == 4)
	{
		if (ft_numbers_control(av[2], '.'))
			return (1);
		if (ft_numbers_control(av[3], '.'))
			return (1);
	}
	return (0);
}
