/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitakinsfator <vitakinsfator@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 17:14:30 by vkinsfat          #+#    #+#             */
/*   Updated: 2024/05/14 13:19:15 by vitakinsfat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap_a(t_stack **a)
{
	int	temp;

	if (!*a || (*a)->next == NULL)
		return ;
	temp = (*a)->num;
	(*a)->num = (*a)->next->num;
	(*a)->next->num = temp;
	temp = (*a)->index;
	(*a)->index = (*a)->next->index;
	(*a)->next->index = temp;
	write(1, "sa\n", 3);
}

void	swap_b(t_stack **b)
{
	int	temp;

	if (!*b || (*b)->next == NULL)
		return ;
	temp = (*b)->num;
	(*b)->num = (*b)->next->num;
	(*b)->next->num = temp;
	temp = (*b)->index;
	(*b)->index = (*b)->next->index;
	(*b)->next->index = temp;
	write(1, "sb\n", 3);
}

void	swap_s(t_stack **a, t_stack **b)
{
	int	temp;

	if (!*a || !*b || (*a)->next == NULL || (*b)->next == NULL)
		return ;
	temp = (*a)->num;
	(*a)->num = (*a)->next->num;
	(*a)->next->num = temp;
	temp = (*a)->index;
	(*a)->index = (*a)->next->index;
	(*a)->next->index = temp;
	temp = (*b)->num;
	(*b)->num = (*b)->next->num;
	(*b)->next->num = temp;
	temp = (*b)->index;
	(*b)->index = (*b)->next->index;
	(*b)->next->index = temp;
	write(1, "ss\n", 3);
}
