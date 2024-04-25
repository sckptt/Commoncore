/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitakinsfator <vitakinsfator@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 17:14:55 by vkinsfat          #+#    #+#             */
/*   Updated: 2024/04/23 20:07:39 by vitakinsfat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rotate_a(t_stack **a)
{
	t_stack	*temp;
	t_stack	*last;

	if (!*a || (*a)->next == NULL)
		return ;
	temp = *a;
	*a = (*a)->next;
	last = ft_lstlast(temp);
	temp->next = NULL;
	last->next = temp;
	write(1, "ra\n", 3);
}

void	rotate_b(t_stack **b)
{
	t_stack	*temp;
	t_stack	*last;

	if (!*b || (*b)->next == NULL)
		return ;
	temp = *b;
	(*b) = (*b)->next;
	last = ft_lstlast(temp);
	temp->next = NULL;
	last->next = temp;
	write(1, "rb\n", 3);
}

void	rotate_r(t_stack **a, t_stack **b)
{
	t_stack	*temp;
	t_stack	*last;

	if (!*a || !*b || (*a)->next == NULL || (*b)->next == NULL)
		return ;
	temp = *a;
	*a = (*a)->next;
	last = ft_lstlast(temp);
	temp->next = NULL;
	last->next = temp;
	temp = *b;
	(*b) = (*b)->next;
	last = ft_lstlast(temp);
	temp->next = NULL;
	last->next = temp;
	write(1, "rr\n", 3);
}
