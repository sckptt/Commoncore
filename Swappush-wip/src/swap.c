/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitakinsfator <vitakinsfator@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 17:14:30 by vkinsfat          #+#    #+#             */
/*   Updated: 2024/04/23 13:53:56 by vitakinsfat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap_a(t_stack **a)
{
	int	temp;

	if (!*a || (*a)->next == NULL)
	{
		printf("Not enough elements to swap!");
		return ;
	}
	temp = (*a)->num;
	(*a)->num = (*a)->next->num;
	(*a)->next->num = temp;
	write(1, "sa\n", 3);
}

void	swap_b(t_stack **b)
{
	int	temp;

	if (!*b || (*b)->next == NULL)
	{
		printf("Not enough elements to swap!");
		return ;
	}
	temp = (*b)->num;
	(*b)->num = (*b)->next->num;
	(*b)->next->num = temp;
	write(1, "sb\n", 3);
}

void	swap_s(t_stack **a, t_stack **b)
{
	int	temp;

	if (!*a || !*b || (*a)->next == NULL || (*b)->next == NULL)
	{
		printf("Not enough elements to swap!");
		return ;
	}
	temp = (*a)->num;
	(*a)->num = (*a)->next->num;
	(*a)->next->num = temp;
	temp = (*b)->num;
	(*b)->num = (*b)->next->num;
	(*b)->next->num = temp;
	write(1, "ss\n", 3);
}
