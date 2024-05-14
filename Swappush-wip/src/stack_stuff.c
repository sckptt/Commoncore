/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_stuff.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitakinsfator <vitakinsfator@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 17:05:11 by vitakinsfat       #+#    #+#             */
/*   Updated: 2024/05/13 19:06:01 by vitakinsfat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../Printf/includes/ft_printf.h"

void	free_stack(t_stack **stack)
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

void	print_stack(t_stack *stack)
{
	ft_printf("Stack:\n");
	while (stack)
	{
		ft_printf("%d\n", stack->num);
		stack = stack->next;
	}
}

void	print_index(t_stack *stack)
{
	ft_printf("Stack index:\n");
	while (stack)
	{
		ft_printf("%d\n", stack->index);
		stack = stack->next;
	}
}

void	create_node(t_stack **stack, int x)
{
	t_stack	*node;
	t_stack	*last;

	last = *stack;
	node = malloc(sizeof(t_stack));
	if (!node)
	{
		ft_printf("%s", "Mistakes were made!");
		exit(1);
	}
	node->num = x;
	node->index = 0;
	node->next = NULL;
	if (!*stack)
	{
		*stack = node;
		return ;
	}
	while (last->next != NULL)
		last = last->next;
	last->next = node;
}

void	create_data(t_data **data)
{
	t_data	*node;

	node = malloc(sizeof(t_data));
	if (!node)
	{
		ft_printf("%s", "Mistakes were made!");
		exit(1);
	}
	node->stack_a = NULL;
	node->stack_b = NULL;
	node->len_a = 0;
	node->len_b = 0;
	node->ac = 0;
	node->av = NULL;
	*data = node;
}

void	stack_init(t_data *data)
{
	int		i;

	i = 0;
	while (data->av[i])
	{
		create_node(&data->stack_a, ft_atoi(data->av[i]));
		data->len_a++;
		i++;
	}
}
