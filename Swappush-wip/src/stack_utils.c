/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkinsfat <vkinsfat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 17:05:11 by vitakinsfat       #+#    #+#             */
/*   Updated: 2024/05/18 15:48:26 by vkinsfat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../Printf/includes/ft_printf.h"

static void	attach_node(t_stack **copy, t_stack *new_node, t_stack **last_node)
{
	if (!*copy)
	{
		*copy = new_node;
		*last_node = new_node;
	}
	else
	{
		(*last_node)->next = new_node;
		*last_node = new_node;
	}
}

t_stack	*copy_stack(t_stack *stack)
{
	t_stack	*copy;
	t_stack	*temp;
	t_stack	*new_node;
	t_stack	*last_node;

	copy = NULL;
	temp = stack;
	while (temp)
	{
		new_node = (t_stack *)malloc(sizeof(t_stack));
		if (!new_node)
			return (NULL);
		new_node->num = temp->num;
		new_node->index = temp->index;
		new_node->next = NULL;
		attach_node(&copy, new_node, &last_node);
		temp = temp->next;
	}
	return (copy);
}

void	delete_node(t_stack **stack, int num)
{
	t_stack	*temp;
	t_stack	*prev;

	temp = *stack;
	if (temp != NULL && temp->num == num)
	{
		*stack = temp->next;
		free(temp);
		return ;
	}
	while (temp != NULL && temp->num != num)
	{
		prev = temp;
		temp = temp->next;
	}
	if (temp == NULL)
		return ;
	prev->next = temp->next;
	free(temp);
}
