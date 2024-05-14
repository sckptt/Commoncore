/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitakinsfator <vitakinsfator@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 12:54:08 by vitakinsfat       #+#    #+#             */
/*   Updated: 2024/05/14 13:06:18 by vitakinsfat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../Printf/includes/ft_printf.h"

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
		if (!copy)
		{
			copy = new_node;
			last_node = new_node;
		}
		else
		{
			last_node->next = new_node;
			last_node = new_node;
		}
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

void	index_init(int counter, t_stack **stack)
{
	t_stack	*temp;
	t_stack	*copy;
	int		small;
	int		index;

	index = 0;
	copy = copy_stack(*stack);
	while (counter)
	{
		temp = *stack;
		small = find_min(copy);
		while (temp)
		{
			if (temp->num == small)
			{
				temp->index = index;
				delete_node(&copy, small);
				index++;
				counter--;
				break ;
			}
			temp = temp->next;
		}
	}
}

void	get_index(t_data **data)
{
	int	counter;

	counter = (*data)->ac;
	index_init(counter, &(*data)->stack_a);
}
