/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitakinsfator <vitakinsfator@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 17:59:34 by vkinsfat          #+#    #+#             */
/*   Updated: 2024/04/23 13:52:50 by vitakinsfat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	reverse_rotate_a(t_stack **a)
{
	t_stack	*temp;
	t_stack	*prev;

	if (!*a || (*a)->next == NULL)
	{
		printf("Not enough elements to reverse rotate!");
		return ;
	}
	temp = *a;
	prev = *a;
	while (prev->next->next != NULL)
		prev = prev->next;
	prev->next->next = temp;
	*a = prev->next;
	prev->next = NULL;
	write(1, "rra\n", 4);
}

void	reverse_rotate_b(t_stack **b)
{
	t_stack	*temp;
	t_stack	*prev;

	if (!*b || (*b)->next == NULL)
	{
		printf("Not enough elements to reverse rotate!");
		return ;
	}
	temp = *b;
	prev = *b;
	while (prev->next->next != NULL)
		prev = prev->next;
	prev->next->next = temp;
	*b = prev->next;
	prev->next = NULL;
	write(1, "rrb\n", 4);
}

void	reverse_rotate_r(t_stack **a, t_stack **b)
{
	t_stack	*temp;
	t_stack	*prev;

	if (!*a || (*a)->next == NULL)
	{
		printf("Not enough elements to reverse rotate!");
		return ;
	}
	temp = *a;
	prev = *a;
	while (prev->next->next != NULL)
		prev = prev->next;
	prev->next->next = temp;
	*a = prev->next;
	prev->next = NULL;
	temp = *b;
	prev = *b;
	while (prev->next->next != NULL)
		prev = prev->next;
	prev->next->next = temp;
	*b = prev->next;
	prev->next = NULL;
	write(1, "rrr\n", 4);
}
