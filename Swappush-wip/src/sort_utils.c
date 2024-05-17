/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitakinsfator <vitakinsfator@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 16:03:28 by vitakinsfat       #+#    #+#             */
/*   Updated: 2024/05/17 14:12:11 by vitakinsfat      ###   ########.fr       */
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

void	index_init(int counter, t_stack **stack)
{
	t_stack	*temp;
	t_stack	*copy;
	int		small;
	int		index;

	index = 0;
	copy = copy_stack(*stack);
	while (counter)
	{
		temp = *stack;
		small = find_min(copy);
		while (temp)
		{
			if (temp->num == small)
			{
				temp->index = index;
				delete_node(&copy, small);
				index++;
				counter--;
				break ;
			}
			temp = temp->next;
		}
	}
}

void	get_index(t_data **data)
{
	int	counter;

	counter = (*data)->ac;
	index_init(counter, &(*data)->stack_a);
}

// int	find_max(t_stack *stack)
// {
// 	t_stack	*temp;
// 	int		max;

// 	max = stack->num;
// 	temp = stack;
// 	while (temp)
// 	{
// 		if (temp->num > max)
// 			max = temp->num;
// 		temp = temp->next;
// 	}
// 	return (max);
// }

// int	get_value(t_data **data)
// {
// 	int	value;

// 	if ((*data)->ac <= 20)
// 	{
// 		value = (*data)->ac / 2;
// 		if ((float)(*data)->ac / 2 - value > 0.5)
// 			value++;
// 	}
// 	if ((*data)->ac > 20 && (*data)->ac <= 100)
// 	{
// 		value = (*data)->ac / 4;
// 		if ((float)(*data)->ac / 4 - value > 0.5)
// 			value++;
// 	}
// 	if ((*data)->ac > 100 && (*data)->ac <= 500)
// 	{
// 		value = (*data)->ac / 8;
// 		if ((float)(*data)->ac / 8 - value > 0.5)
// 			value++;
// 	}
// 	return (value);
// }