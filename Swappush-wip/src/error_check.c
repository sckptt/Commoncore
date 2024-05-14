/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitakinsfator <vitakinsfator@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 14:14:09 by vitakinsfat       #+#    #+#             */
/*   Updated: 2024/04/30 16:15:02 by vitakinsfat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../Printf/includes/ft_printf.h"

static void	is_valid(char *num)
{
	int	i;

	i = 0;
	if (num[0] == '-' || num[0] == '+')
	{
		if (num[1] == '\0')
		{
			ft_printf("Error2\n");
			exit(1);
		}
		i++;
	}
	while (num[i])
	{
		if (!ft_isdigit(num[i]))
		{
			ft_printf("Error3\n");
			exit(1);
		}
		i++;
	}
}

static void	is_not_sorted(int argc, char **argv)
{
	int	i;

	i = 0;
	while (i + 1 < argc)
	{
		if (ft_atoi(argv[i]) > ft_atoi(argv[i + 1]))
			return ;
		i++;
	}
	exit(0);
}

static void	has_no_duplicates(int ac, char **av)
{
	int	i;
	int	j;

	i = 0;
	while (i < ac)
	{
		j = i + 1;
		while (j < ac)
		{
			if (ft_atoi(av[i]) == ft_atoi(av[j]))
			{
				ft_printf("Error4\n");
				exit(1);
			}
			j++;
		}
		i++;
	}
}

int	error_check(int ac, char **av)
{
	int	i;

	i = 0;
	if (ac == 1)
	{
		ft_printf("Error1\n");
		exit(1);
	}
	//printf("Before is_valid\n");
	while (i < ac)
	{
		is_valid(av[i]);
		i++;
	}
	//printf("Before has_no_duplicates\n");
	has_no_duplicates(ac, av);
	//printf("Before is_not_sorted\n");
	is_not_sorted(ac, av);
	return (0);
}
