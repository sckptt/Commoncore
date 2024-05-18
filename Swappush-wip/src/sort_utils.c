/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkinsfat <vkinsfat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 16:03:28 by vitakinsfat       #+#    #+#             */
/*   Updated: 2024/05/18 15:34:41 by vkinsfat         ###   ########.fr       */
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

int	find_position(t_stack *stack, int min)
{
	t_stack	*temp;
	int		position;

	position = 0;
	temp = stack;
	while (temp->num != min)
	{
		position++;
		temp = temp->next;
	}
	return (position);
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

static void	index_init(int counter, t_stack **stack)
{
	t_stack	*temp;
	t_stack	*copy;
	int		small;

	copy = copy_stack(*stack);
	while (counter)
	{
		temp = *stack;
		small = find_min(copy);
		while (temp)
		{
			if (temp->num == small)
			{
				temp->index = counter;
				delete_node(&copy, small);
				counter--;
				break ;
			}
			temp = temp->next;
		}
	}
	free_stack(&copy);
}

void	get_index(t_data **data)
{
	int	counter;

	counter = (*data)->ac;
	index_init(counter, &(*data)->stack_a);
}
