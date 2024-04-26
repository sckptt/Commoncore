/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitakinsfator <vitakinsfator@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 16:43:24 by vitakinsfat       #+#    #+#             */
/*   Updated: 2024/04/27 01:00:31 by vitakinsfat      ###   ########.fr       */
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

void	sort_two(t_data **data)
{
	if ((*data)->stack_a->num > (*data)->stack_a->next->num)
		swap_a(&(*data)->stack_a);
}

void	small_sort(t_data **data)
{
	int	min;
	int	index;

	if ((*data)->len == 2)
		sort_two(data);
	if ((*data)->len > 2 && (*data)->len <= 10)
	{
		while (!(sorted_already((*data)->stack_a)))
		{
			min = find_min((*data)->stack_a);
			index = find_index((*data)->stack_a, min);
			while ((*data)->stack_a->num != min)
			{
				if (index < (*data)->len / 2)
					rotate_a(&(*data)->stack_a);
				else if (index >= (*data)->len / 2)
					reverse_rotate_a(&(*data)->stack_a);
			}
			if (sorted_already((*data)->stack_a))
				break ;
			push_b(&(*data)->stack_a, &(*data)->stack_b);
		}
		while ((*data)->stack_b)
			push_a(&(*data)->stack_a, &(*data)->stack_b);
	}
}
