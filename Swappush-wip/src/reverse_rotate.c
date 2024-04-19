/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitakinsfator <vitakinsfator@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 17:59:34 by vkinsfat          #+#    #+#             */
/*   Updated: 2024/04/19 19:50:22 by vitakinsfat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	reverse_rotate_a(t_stack **a)
{
	t_stack *temp;
	t_stack *prev;
	
	if (!*a || (*a)->next == NULL)
	{
		printf("Not enough elements to reverse rotate!");
		exit(0);
	}
	temp = *a;
	prev = *a;
	while (prev->next->next != NULL)
		prev = prev->next;
	prev->next->next = temp;
	*a = prev->next;
	temp->next = NULL;
	write(1, "rra\n", 4);
}

// void	reverse_rotate_b(t_stack **b)
// {
// 	write(1, "rrb\n", 4);
// }

// void	reverse_rotate_r(t_stack **a, t_stack **b)
// {
// 	write(1, "rrr\n", 4);
// }
