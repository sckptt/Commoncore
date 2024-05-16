/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitakinsfator <vitakinsfator@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 16:43:24 by vitakinsfat       #+#    #+#             */
/*   Updated: 2024/05/16 17:52:42 by vitakinsfat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../Printf/includes/ft_printf.h"

void	sort_two(t_data **data)
{
	if ((*data)->stack_a->num > (*data)->stack_a->next->num)
		swap_a(&(*data)->stack_a);
}

void	last_command(t_data **data)
{
	if ((*data)->stack_a->num < (*data)->stack_a->next->num
		&& (*data)->stack_a->next->num > (*data)->stack_a->next->next->num
		&& (*data)->stack_a->num < (*data)->stack_a->next->next->num)
	{
		reverse_rotate_a(&(*data)->stack_a);
		swap_a(&(*data)->stack_a);
	}
}

void	sort_three(t_data **data)
{
	if ((*data)->stack_a->num > (*data)->stack_a->next->num
		&& (*data)->stack_a->next->num < (*data)->stack_a->next->next->num
		&& (*data)->stack_a->num < (*data)->stack_a->next->next->num)
		swap_a(&(*data)->stack_a);
	else if ((*data)->stack_a->num < (*data)->stack_a->next->num
		&& (*data)->stack_a->next->num > (*data)->stack_a->next->next->num
		&& (*data)->stack_a->num > (*data)->stack_a->next->next->num)
		reverse_rotate_a(&(*data)->stack_a);
	else if ((*data)->stack_a->num > (*data)->stack_a->next->num
		&& (*data)->stack_a->next->num > (*data)->stack_a->next->next->num
		&& (*data)->stack_a->num > (*data)->stack_a->next->next->num)
	{
		rotate_a(&(*data)->stack_a);
		swap_a(&(*data)->stack_a);
	}
	else if ((*data)->stack_a->num > (*data)->stack_a->next->num
		&& (*data)->stack_a->next->num < (*data)->stack_a->next->next->num
		&& (*data)->stack_a->num > (*data)->stack_a->next->next->num)
		rotate_a(&(*data)->stack_a);
	else
		last_command(data);
}

void	sort_more(t_data **data)
{
	int	min;
	int	position;

	while ((*data)->len_a > 3)
	{
		min = find_min((*data)->stack_a);
		position = find_position((*data)->stack_a, min);
		while ((*data)->stack_a->num != min)
		{
			if (position < (*data)->ac / 2)
				rotate_a(&(*data)->stack_a);
			else if (position >= (*data)->ac / 2)
				reverse_rotate_a(&(*data)->stack_a);
		}
		push_b(data);
	}
	sort_three(data);
	while ((*data)->stack_b)
		push_a(data);
}

void	small_sort(t_data **data)
{
	if ((*data)->ac == 2)
		sort_two(data);
	if ((*data)->ac == 3)
		sort_three(data);
	if ((*data)->ac > 3 && (*data)->ac <= 10)
		sort_more(data);
	print_stack((*data)->stack_a);
}
