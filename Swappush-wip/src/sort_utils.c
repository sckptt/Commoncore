/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitakinsfator <vitakinsfator@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 16:03:28 by vitakinsfat       #+#    #+#             */
/*   Updated: 2024/05/14 13:04:28 by vitakinsfat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../Printf/includes/ft_printf.h"

int	find_min(t_stack *stack)
{
	t_stack	*temp;
	int		min;

	min = stack->num;
	temp = stack;
	while (temp)
	{
		if (temp->num < min)
			min = temp->num;
		temp = temp->next;
	}
	return (min);
}

int	find_index(t_stack *stack, int min)
{
	t_stack	*temp;
	int		index;

	index = 0;
	temp = stack;
	while (temp->num != min)
	{
		index++;
		temp = temp->next;
	}
	return (index);
}

int	sorted_already(t_stack *stack)
{
	t_stack	*temp;

	temp = stack;
	while (temp && temp->next)
	{
		if (temp->num > temp->next->num)
			return (0);
		temp = temp->next;
	}
	return (1);
}
