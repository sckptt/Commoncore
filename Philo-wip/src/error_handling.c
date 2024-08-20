/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkinsfat <vkinsfat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 20:53:37 by vkinsfat          #+#    #+#             */
/*   Updated: 2024/08/20 18:04:23 by vkinsfat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	else
		return (0);
}

static long	ft_atol(char *str)
{
	int		i;
	long	one;
	long	result;

	i = 0;
	one = 1;
	result = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == 45 || str[i] == 43)
	{
		if (str[i] == 45)
			one = -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * one);
}

static int	digits_only(char **av)
{
	int	i;
	int	j;

	i = 0;
	while (av[++i])
	{
		j = -1;
		while (av[i][++j])
		{
			if (!ft_isdigit(av[i][j]))
				return (ft_putstr_fd(NON_NUMERIC_ERROR, 2), 1);
		}
	}
	return (0);
}

static int	check_limits(int ac, char **av)
{
	int		i;
	long	arg;

	i = 0;
	while (++i < ac)
	{
		if (i == 5)
		{
			arg = ft_atol(av[i]);
			if (arg < 0 || arg > INT_MAX)
				return (ft_putstr_fd(OUT_OF_RANGE_ERROR, 2), 1);
		}
		else
		{
			arg = ft_atol(av[i]);
			if (arg < 1 || arg > INT_MAX)
				return (ft_putstr_fd(OUT_OF_RANGE_ERROR, 2), 1);
		}
	}
	return (0);
}

int	check_args(int ac, char **av)
{
	if (ac != 5 && ac != 6)
		return (ft_putstr_fd(WRONG_NUMBER_OF_ARGS_ERROR, 2), 1);
	if (digits_only(av) != 0)
		return (1);
	if (check_limits(ac, av) != 0)
		return (1);
	return (0);
}
