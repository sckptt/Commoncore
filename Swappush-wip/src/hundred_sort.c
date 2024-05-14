/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hundred_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitakinsfator <vitakinsfator@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 16:32:44 by vitakinsfat       #+#    #+#             */
/*   Updated: 2024/05/14 18:39:31 by vitakinsfat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../Printf/includes/ft_printf.h"

int	get_value(t_data **data)
{
	int	value;

	if ((*data)->ac <= 20)
	{
		value = (*data)->ac / 2;
		if ((float)(*data)->ac / 2 - value > 0.5)
			value++;
	}
	if ((*data)->ac > 20 && (*data)->ac <= 100)
	{
		value = (*data)->ac / 4;
		if ((float)(*data)->ac / 4 - value > 0.5)
			value++;
	}
	if ((*data)->ac > 100 && (*data)->ac <= 500)
	{
		value = (*data)->ac / 8;
		if ((float)(*data)->ac / 8 - value > 0.5)
			value++;
	}
	return (value);
}

void	step_1(t_data **data, int value)
{
	int	push_counter;

	push_counter = 0;
	while (push_counter < value)
	{
		if ((*data)->stack_a->index < value)
		{
			push_b(data);
			push_counter++;
		}
		else
			rotate_a(&(*data)->stack_a);
	}
	while (push_counter < value * 2)
	{
		if ((*data)->stack_a->index < value * 2)
		{
			push_b(data);
			push_counter++;
		}
		else
			rotate_a(&(*data)->stack_a);
	}
}

void	step_2(t_data **data, int value)
{
	int	push_counter;

	push_counter = 0;
	while (push_counter < value)
	{
		if ((*data)->stack_a->index < value * 3)
		{
			push_b(data);
			push_counter++;
		}
		else
			rotate_a(&(*data)->stack_a);
	}
	while ((*data)->len_a > 3)
	{
		if ((*data)->stack_a->index <= value * 4 - 3)
			push_b(data);
		else
			rotate_a(&(*data)->stack_a);
	}
	sort_three(data);
}

int	find_max(t_stack *stack)
{
	t_stack	*temp;
	int		max;

	max = stack->num;
	temp = stack;
	while (temp)
	{
		if (temp->num > max)
			max = temp->num;
		temp = temp->next;
	}
	return (max);
}

void	step_3(t_data **data)
{
	int	max;
	int	index;

	while ((*data)->stack_b)
	{
		if ((*data)->stack_a->index - (*data)->stack_b->index == 1)
			push_a(data);
		else
		{
			max = find_max((*data)->stack_b);
			index = find_index((*data)->stack_b, max);
			if (index < (*data)->len_b / 2)
				rotate_b(&(*data)->stack_b);
			else if (index >= (*data)->len_b / 2)
				reverse_rotate_b(&(*data)->stack_b);
		}
	}
}

void	hundred_sort(t_data **data)
{
	int	value;

	value = get_value(data);
	get_index(data);
	step_1(data, value);
	step_2(data, value);
	step_3(data);
}
