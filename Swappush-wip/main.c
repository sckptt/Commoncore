/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkinsfat <vkinsfat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 19:12:23 by vkinsfat          #+#    #+#             */
/*   Updated: 2024/04/18 20:37:51 by vkinsfat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void create_nodes(t_stack **a, int x)
{
	t_stack *node;
	t_stack *last = *a;

	node = malloc(sizeof(t_stack));
	if (!node)
	{
		printf("%s", "Mistakes were made!");
		exit(1);
	}
	node->num = x;
	node->next = NULL;
	if (!*a)
	{
		*a = node;
		return;
	}
	while (last->next != NULL)
		last = last->next;
	last->next = node;
}

int main(void)
{
	int arguments[3] = {3, 1, 2};
	t_stack *stack_a;
	// t_stack *stack_b;
	int i;
	t_stack *temp_stack;
	
	stack_a = NULL;
	// stack_b = NULL;
	i = 0;
	while (i < 3)
	{
		create_nodes(&stack_a, arguments[i]);
		i++;
	}
	temp_stack = stack_a;
	while (temp_stack)
	{
		printf("%d\n", temp_stack->num);
		temp_stack = temp_stack->next;
	}
	return (0);
}