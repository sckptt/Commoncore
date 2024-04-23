/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkinsfat <vkinsfat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 00:24:37 by vitakinsfat       #+#    #+#             */
/*   Updated: 2024/04/23 17:51:48 by vkinsfat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	create_node(t_stack **stack, int x)
{
	t_stack	*node;
	t_stack	*last;

	last = *stack;
	node = malloc(sizeof(t_stack));
	if (!node)
	{
		printf("%s", "Mistakes were made!");
		exit(1);
	}
	node->num = x;
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

int	main(int argc, char **argv)
{
	int		i;
	t_stack	*stack_a;
	t_stack	*temp_stack_a;
	//t_stack *stack_b;

	stack_a = NULL;
	//stack_b = NULL;
	i = 1;
	error_check(argc, argv);
	while (i < argc)
	{
		create_node(&stack_a, ft_atoi(argv[i]));
		i++;
	}
	
	temp_stack_a = stack_a;
	printf("\nA:\n");
	while (temp_stack_a)
	{
		printf("%d\n", temp_stack_a->num);
		temp_stack_a = temp_stack_a->next;
	}
	free_stack(&stack_a);
	return (0);
}
