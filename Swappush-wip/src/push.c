/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitakinsfator <vitakinsfator@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 17:14:13 by vkinsfat          #+#    #+#             */
/*   Updated: 2024/04/19 18:39:28 by vitakinsfat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push_a(t_stack **a, t_stack **b)
{
	t_stack	*temp;

	if (!*b)
	{
		printf("%s", "Stack b is empty!");
		exit(0);
	}
	temp = *b;
	*b = (*b)->next;
	temp->next = *a;
	*a = temp;
	write(1, "pa\n", 3);
}

void	push_b(t_stack **a, t_stack **b)
{
	t_stack	*temp;

	if (!*a)
	{
		printf("%s", "Stack a is empty!");
		exit(0);
	}
	temp = *a;
	*a = (*a)->next;
	temp->next = *b;
	*b = temp;
	write(1, "pb\n", 3);
}
