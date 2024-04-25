/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitakinsfator <vitakinsfator@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 14:14:09 by vitakinsfat       #+#    #+#             */
/*   Updated: 2024/04/24 18:29:53 by vitakinsfat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../Printf/includes/ft_printf.h"

void	free_stack(t_stack **stack)
{
	t_stack	*temp;

	if (!*stack)
		return ;
	while (*stack)
	{
		temp = *stack;
		*stack = (*stack)->next;
		free(temp);
	}
	stack = NULL;
}

static void	is_valid(char *num)
{
	int	i;

	i = 0;
	if (num[0] == '-' || num[0] == '+')
	{
		if (num[1] == '\0')
		{
			ft_printf("Error\n");
			exit(1);
		}
		i++;
	}
	while (num[i])
	{
		if (!ft_isdigit(num[i]))
		{
			ft_printf("Error\n");
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

	i = 1;
	while (i < ac)
	{
		j = i + 1;
		while (j < ac)
		{
			if (ft_atoi(av[i]) == ft_atoi(av[j]))
			{
				ft_printf("Error\n");
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

	i = 1;
	if (ac < 2)
		exit(0);
	if (ac == 2)
	{
		ft_printf("Error\n");
		exit(1);
	}
	has_no_duplicates(ac, av);
	while (i < ac)
	{
		is_valid(av[i]);
		i++;
	}
	is_not_sorted(ac, av);
	return (0);
}
