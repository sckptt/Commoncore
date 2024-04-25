/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitakinsfator <vitakinsfator@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 00:24:37 by vitakinsfat       #+#    #+#             */
/*   Updated: 2024/04/25 20:50:19 by vitakinsfat      ###   ########.fr       */
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

void	print_stack(t_stack *stack)
{
	ft_printf("Stack:\n");
	while (stack)
	{
		ft_printf("%d\n", stack->num);
		stack = stack->next;
	}
}

int	stack_init(char **argv)
{
	int		i;
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	i = 0;
	while (argv[i])
	{
		create_node(&stack_a, ft_atoi(argv[i]));
		i++;
	}
	print_stack(stack_a);
	print_stack(stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}

int	main(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc < 2)
		exit(0);
	if (argc > 1)
	{
		argv++;
		if (argc == 2)
		{
			argv = ft_split(*argv, ' ');
			argc = argv_len(argv);
		}
		else
			argc--;
	}
	printf("%d\n", argc);
	while (argv[i])
	{
		printf("%s\n", argv[i]);
		i++;
	}
	printf("Before error check\n");
	error_check(argc, argv);
	printf("After error check\n");
	stack_init(argv);
	return (0);
}
