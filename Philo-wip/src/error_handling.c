/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitakinsfator <vitakinsfator@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 16:35:57 by vitakinsfat       #+#    #+#             */
/*   Updated: 2024/07/02 20:07:43 by vitakinsfat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	check_optional_arg(char *str)
{
	if (ft_atoi(str) < 0)
	{
		ft_putstr_fd("Error! Last argument is less than 0!\n", 2);
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
		while (av[i][j])
		{
			if (ft_isdigit(av[i][j]) || av[i][j] == '-' || av[i][j] == '+')
				j++;
			else
			{
				ft_putstr_fd("Error! An argument is not numeric!\n", 2);
				return (1);
			}
		}
		i++;
	}
	return (0);
}

static int	check_limits(char **av)
{
	int	i;

	i = 1;
	if (ft_atoi(av[1]) > 200)
	{
		ft_putstr_fd("Error! First argument is more than 200!\n", 2);
		return (1);
	}
	while (i < 5)
	{
		if (ft_atoi(av[i]) < 1)
		{
			ft_putstr_fd("Error! One of the arguments is less than 1!\n", 2);
			return (1);
		}
		i++;
	}
	return (0);
}

int	check_args(char **av)
{
	if (digits_only(av) != 0)
		return (1);
	if (check_limits(av) != 0)
		return (1);
	if (av[5])
	{
		if (check_optional_arg(av[5]) != 0)
			return (1);
	}
	return (0);
}
