/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitakinsfator <vitakinsfator@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 17:14:13 by vkinsfat          #+#    #+#             */
/*   Updated: 2024/04/30 17:24:39 by vitakinsfat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push_a(t_data **data)
{
	t_stack	*temp;

	if (!(*data)->stack_b)
		return ;
	temp = (*data)->stack_b;
	(*data)->stack_b = (*data)->stack_b->next;
	temp->next = (*data)->stack_a;
	(*data)->stack_a = temp;
	(*data)->len_a++;
	(*data)->len_b--;
	write(1, "pa\n", 3);
}

void	push_b(t_data **data)
{
	t_stack	*temp;

	if (!(*data)->stack_a)
		return ;
	temp = (*data)->stack_a;
	(*data)->stack_a = (*data)->stack_a->next;
	temp->next = (*data)->stack_b;
	(*data)->stack_b = temp;
	(*data)->len_b++;
	(*data)->len_a--;
	write(1, "pb\n", 3);
}
