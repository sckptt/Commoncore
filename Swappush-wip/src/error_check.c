/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitakinsfator <vitakinsfator@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 14:14:09 by vitakinsfat       #+#    #+#             */
/*   Updated: 2024/04/23 15:55:38 by vitakinsfat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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

void	is_valid(char *num)
{
	int	i;

	i = 0;
	if (num[0] == '-' || num[0] == '+')
	{
		if (num[1] == '\0')
		{
			printf("Error\n");
			exit(1);
		}
		i++;
	}
	while (num[i])
	{
		if (!(num[i] >= 48 && num[i] <= 57))
		{
			printf("Error\n");
			exit(1);
		}
		i++;
	}
}

void	is_not_sorted(t_stack *stack)
{
	t_stack	*temp;

	temp = stack;
	while (temp->next)
	{
		if (temp->num > temp->next->num)
			return ;
		temp = temp->next;
	}
	free_stack(&stack);
	exit(0);
}

void	has_no_duplicates(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	while (i < ac)
	{
		while (j < ac)
		{
			if (ft_atoi(av[i]) == ft_atoi(av[j]))
			{
				printf("Duplication error\n");
				exit(1);
			}
			j++;
		}
		i++;
		j = i + 1;
	}
}
