/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkinsfat <vkinsfat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 14:14:09 by vitakinsfat       #+#    #+#             */
/*   Updated: 2024/05/18 19:40:38 by vkinsfat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../Printf/includes/ft_printf.h"

static void	atoi_check(t_data *data)
{
	int		i;
	long	number;

	i = 0;
	while (i < data->ac)
	{
		number = ft_atoi_long(data->av[i]);
		if (number > 2147483647 || number < -2147483648)
		{
			write(2, "Error\n", 6);
			free_data(data);
			exit(1);
		}
		i++;
	}
}

static int	is_valid(char *num)
{
	int	i;

	i = 0;
	if (num[0] == '-' || num[0] == '+')
	{
		if (num[1] == '\0')
			return (0);
		i++;
	}
	while (num[i])
	{
		if (!ft_isdigit(num[i]))
			return (0);
		i++;
	}
	return (1);
}

static void	is_not_sorted(t_data *data)
{
	int	i;

	i = 0;
	while (i + 1 < data->ac)
	{
		if (ft_atoi(data->av[i]) > ft_atoi(data->av[i + 1]))
			return ;
		i++;
	}
	free_data(data);
	exit(0);
}

static void	has_no_duplicates(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->ac)
	{
		j = i + 1;
		while (j < data->ac)
		{
			if (ft_atoi(data->av[i]) == ft_atoi(data->av[j]))
			{
				write(2, "Error\n", 6);
				free_data(data);
				exit(1);
			}
			j++;
		}
		i++;
	}
}

int	error_check(t_data *data)
{
	int	i;
	int	flag;

	i = 0;
	while (i < data->ac)
	{
		flag = is_valid(data->av[i]);
		if (!flag)
		{
			write(2, "Error\n", 6);
			free_data(data);
			exit(1);
		}
		i++;
	}
	atoi_check(data);
	has_no_duplicates(data);
	is_not_sorted(data);
	if (data->ac == 1)
	{
		free_data(data);
		exit(0);
	}
	return (0);
}
