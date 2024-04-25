/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitakinsfator <vitakinsfator@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 00:24:37 by vitakinsfat       #+#    #+#             */
/*   Updated: 2024/04/24 18:29:17 by vitakinsfat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../Printf/includes/ft_printf.h"

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
	ft_printf("\nA:\n");
	while (temp_stack_a)
	{
		ft_printf("%d\n", temp_stack_a->num);
		temp_stack_a = temp_stack_a->next;
	}
	free_stack(&stack_a);
	return (0);
}
