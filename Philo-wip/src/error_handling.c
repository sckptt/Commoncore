/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitakinsfator <vitakinsfator@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 16:35:57 by vitakinsfat       #+#    #+#             */
/*   Updated: 2024/07/15 15:50:01 by vitakinsfat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	check_optional_arg(char *str)
{
	long	arg;

	arg = ft_atol(str);
	if (arg < 0 || arg > INT_MAX)
	{
		ft_putstr_fd("Error! Last argument is out of range!\n", 2);
		return (1);
	}
	return (0);
}

static int	digits_only(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = 0;
		if (av[i][j] == '-' || av[i][j] == '+')
			j++;
		while (av[i][j])
		{
			if (!ft_isdigit(av[i][j]))
			{
				ft_putstr_fd("Error! Argument ", 2);
				ft_putstr_fd(av[i], 2);
				ft_putstr_fd(" is not numeric!\n", 2);
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

static int	check_limits(int ac, char **av)
{
	int		i;
	long	arg;

	i = 1;
	while (i < ac)
	{
		arg = ft_atol(av[i]);
		if (arg < 1 || arg > INT_MAX)
		{
			ft_putstr_fd("Error! Argument ", 2);
			ft_putstr_fd(av[i], 2);
			ft_putstr_fd(" is out of range!\n", 2);
			return (1);
		}
		i++;
	}
	return (0);
}

int	check_args(int ac, char **av)
{
	if (ac != 5 && ac != 6)
	{
		ft_putstr_fd("Error! Wrong number of arguments!\n", 2);
		return (1);
	}
	if (digits_only(av) != 0)
		return (1);
	if (check_limits(ac, av) != 0)
		return (1);
	if (ac == 6)
	{
		if (check_optional_arg(av[5]) != 0)
			return (1);
	}
	return (0);
}
