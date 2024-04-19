/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitakinsfator <vitakinsfator@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 19:12:23 by vkinsfat          #+#    #+#             */
/*   Updated: 2024/04/19 20:51:21 by vitakinsfat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	create_nodes(t_stack **stack, int x)
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

int	push_demo(void)
{
	int		arguments[5] = {4, 3, 1, 2, 5};
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_stack	*temp_stack_a;
	t_stack	*temp_stack_b;
	t_stack	*temp_stack_a1;
	t_stack	*temp_stack_b1;
	int		i;

	stack_a = NULL;
	stack_b = NULL;
	i = 0;
	while (i < 5)
	{
		create_nodes(&stack_a, arguments[i]);
		i++;
	}
	printf("Now we push to b!\n");
	push_b(&stack_a, &stack_b);
	temp_stack_a = stack_a;
	temp_stack_b = stack_b;
	printf("\nA:\n");
	while (temp_stack_a)
	{
		printf("%d\n", temp_stack_a->num);
		temp_stack_a = temp_stack_a->next;
	}
	printf("\nB:\n");
	while (temp_stack_b)
	{
		printf("%d\n", temp_stack_b->num);
		temp_stack_b = temp_stack_b->next;
	}
	printf("\nNow we push back to a!\n");
	push_a(&stack_a, &stack_b);
	temp_stack_a1 = stack_a;
	temp_stack_b1 = stack_b;
	printf("\nA:\n");
	while (temp_stack_a1)
	{
		printf("%d\n", temp_stack_a1->num);
		temp_stack_a1 = temp_stack_a1->next;
	}
	printf("\nB:\n");
	while (temp_stack_b1)
	{
		printf("%d\n", temp_stack_b1->num);
		temp_stack_b1 = temp_stack_b1->next;
	}
	return (0);
}

int	swap_demo(void)
{
	int		arguments[5] = {4, 3, 1, 2, 5};
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_stack	*temp_stack_a;
	t_stack	*temp_stack_b;
	int		i;

	stack_a = NULL;
	stack_b = NULL;
	i = 0;
	while (i < 5)
	{
		create_nodes(&stack_a, arguments[i]);
		create_nodes(&stack_b, arguments[i]);
		i++;
	}
	printf("Now we swap A and B!\n\n");
	swap_s(&stack_a, &stack_b);
	temp_stack_a = stack_a;
	temp_stack_b = stack_b;
	printf("\nA:\n");
	while (temp_stack_a)
	{
		printf("%d\n", temp_stack_a->num);
		temp_stack_a = temp_stack_a->next;
	}
	printf("\nB:\n");
	while (temp_stack_b)
	{
		printf("%d\n", temp_stack_b->num);
		temp_stack_b = temp_stack_b->next;
	}
	return (0);
}

int	rotate_demo(void)
{
	int		arguments[5] = {4, 3, 1, 2, 5};
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_stack	*temp_stack_a;
	t_stack	*temp_stack_b;
	int		i;

	stack_a = NULL;
	stack_b = NULL;
	i = 0;
	while (i < 5)
	{
		create_nodes(&stack_a, arguments[i]);
		create_nodes(&stack_b, arguments[i]);
		i++;
	}
	printf("Now we rotate A and B!\n\n");
	rotate_r(&stack_a, &stack_b);
	temp_stack_a = stack_a;
	temp_stack_b = stack_b;
	printf("\nA:\n");
	while (temp_stack_a)
	{
		printf("%d\n", temp_stack_a->num);
		temp_stack_a = temp_stack_a->next;
	}
	printf("\nB:\n");
	while (temp_stack_b)
	{
		printf("%d\n", temp_stack_b->num);
		temp_stack_b = temp_stack_b->next;
	}
	return (0);
}

int reverse_rotate_demo(void)
{
	int		arguments[5] = {4, 3, 1, 2, 5};
	t_stack	*stack_a;
	t_stack *stack_b;
	t_stack	*temp_stack_a;
	t_stack *temp_stack_b;
	int		i;

	stack_a = NULL;
	stack_b = NULL;
	i = 0;
	while (i < 5)
	{
		create_nodes(&stack_a, arguments[i]);
		create_nodes(&stack_b, arguments[i]);
		i++;
	}
	printf("Now we reverse rotate A!\n\n");
	reverse_rotate_r(&stack_a, &stack_b);
	temp_stack_a = stack_a;
	temp_stack_b = stack_b;
	printf("\nA:\n");
	while (temp_stack_a)
	{
		printf("%d\n", temp_stack_a->num);
		temp_stack_a = temp_stack_a->next;
	}
	printf("\nB:\n");
	while (temp_stack_b)
	{
		printf("%d\n", temp_stack_b->num);
		temp_stack_b = temp_stack_b->next;
	}
	return (0);
}

int	main(void)
{
	printf("Original sequence is 4, 3, 1, 2, 5\n");
	push_demo();
	printf("\n");
	swap_demo();
	printf("\n");
	rotate_demo();
	printf("\n");
	reverse_rotate_demo();
}
