/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitakinsfator <vitakinsfator@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 16:43:24 by vitakinsfat       #+#    #+#             */
/*   Updated: 2024/04/28 16:09:29 by vitakinsfat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../Printf/includes/ft_printf.h"

void	sort_two(t_data **data)
{
	if ((*data)->stack_a->num > (*data)->stack_a->next->num)
		swap_a(&(*data)->stack_a);
}

void	sort_three(t_data **data)
{
	if ((*data)->stack_a->num < (*data)->stack_a->next->num
		&& (*data)->stack_a->next->num > (*data)->stack_a->next->next->num
		&& (*data)->stack_a->num < (*data)->stack_a->next->next->num)
	{
		reverse_rotate_a(&(*data)->stack_a);
		swap_a(&(*data)->stack_a);
	}
	if ((*data)->stack_a->num > (*data)->stack_a->next->num
		&& (*data)->stack_a->next->num < (*data)->stack_a->next->next->num
		&& (*data)->stack_a->num < (*data)->stack_a->next->next->num)
		swap_a(&(*data)->stack_a);
	if ((*data)->stack_a->num < (*data)->stack_a->next->num
		&& (*data)->stack_a->next->num > (*data)->stack_a->next->next->num
		&& (*data)->stack_a->num > (*data)->stack_a->next->next->num)
		rotate_a(&(*data)->stack_a);
	if ((*data)->stack_a->num > (*data)->stack_a->next->num
		&& (*data)->stack_a->next->num > (*data)->stack_a->next->next->num
		&& (*data)->stack_a->num > (*data)->stack_a->next->next->num)
	{
		rotate_a(&(*data)->stack_a);
		swap_a(&(*data)->stack_a);
	}
	if ((*data)->stack_a->num > (*data)->stack_a->next->num
		&& (*data)->stack_a->next->num < (*data)->stack_a->next->next->num
		&& (*data)->stack_a->num > (*data)->stack_a->next->next->num)
		rotate_a(&(*data)->stack_a);
}

void	sort_more(t_data **data)
{
	int	min;
	int	index;

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

void	small_sort(t_data **data)
{
	if ((*data)->len == 2)
		sort_two(data);
	if ((*data)->len == 3)
		sort_three(data);
	if ((*data)->len > 3 && (*data)->len <= 10)
		sort_more(data);
}
