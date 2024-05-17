/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitakinsfator <vitakinsfator@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 17:05:11 by vitakinsfat       #+#    #+#             */
/*   Updated: 2024/05/17 18:53:09 by vitakinsfat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../Printf/includes/ft_printf.h"

static void	free_stack(t_stack **stack)
{
	t_stack	*temp;

	if (!*stack)
		return ;
	while (*stack)
	{
		temp = *stack;
		*stack = (*stack)->next;
		free(temp);
	}
	stack = NULL;
}

void	free_data(t_data *data)
{
	int	i;

	free_stack(&data->stack_a);
	free_stack(&data->stack_b);
	if (data->av != NULL && data->allocation == 1)
	{
		i = 0;
		while (data->av[i])
		{
			free(data->av[i]);
			i++;
		}
		free(data->av);
	}
	free(data);
}

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
	temp = NULL;
}
