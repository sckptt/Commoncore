/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   demonstration.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitakinsfator <vitakinsfator@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 19:12:23 by vkinsfat          #+#    #+#             */
/*   Updated: 2024/04/30 15:59:37 by vitakinsfat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../Printf/includes/ft_printf.h"

// int	push_demo(void)
// {
// 	int		arguments[5] = {4, 3, 1, 2, 5};
//     t_data	*data;
// 	int		i;

//     data = NULL;
// 	i = 0;
//     create_data(&data);
//     while (i < 5)
// 	{
// 		create_node(&data->stack_a, arguments[i]);
// 		data->len_a++;
// 		i++;
// 	}
// 	printf("Now we push to b!\n");
// 	push_b(&data);
//     print_stack(data->stack_a);
//     print_stack(data->stack_b);
//     printf("len_a: %d\n", data->len_a);
//     printf("len_b: %d\n", data->len_b);
// 	printf("\nNow we push back to a!\n");
// 	push_a(&data);
// 	print_stack(data->stack_a);
//     print_stack(data->stack_b);
//     printf("len_a: %d\n", data->len_a);
//     printf("len_b: %d\n", data->len_b);
// 	free_stack(&data->stack_a);
// 	free_stack(&data->stack_b);
// 	return (0);
// }

// int	swap_demo(void)
// {
// 	int		arguments[5] = {4, 3, 1, 2, 5};
// 	t_stack	*stack_a;
// 	t_stack	*stack_b;
// 	t_stack	*temp_stack_a;
// 	t_stack	*temp_stack_b;
// 	int		i;

// 	stack_a = NULL;
// 	stack_b = NULL;
// 	i = 0;
// 	while (i < 5)
// 	{
// 		create_node(&stack_a, arguments[i]);
// 		create_node(&stack_b, arguments[i]);
// 		i++;
// 	}
// 	printf("Now we swap A and B!\n\n");
// 	swap_s(&stack_a, &stack_b);
// 	temp_stack_a = stack_a;
// 	temp_stack_b = stack_b;
// 	printf("\nA:\n");
// 	while (temp_stack_a)
// 	{
// 		printf("%d\n", temp_stack_a->num);
// 		temp_stack_a = temp_stack_a->next;
// 	}
// 	printf("\nB:\n");
// 	while (temp_stack_b)
// 	{
// 		printf("%d\n", temp_stack_b->num);
// 		temp_stack_b = temp_stack_b->next;
// 	}
// 	free_stack(&stack_a);
// 	free_stack(&stack_b);
// 	return (0);
// }

// int	rotate_demo(void)
// {
// 	int		arguments[5] = {4, 3, 1, 2, 5};
// 	t_stack	*stack_a;
// 	t_stack	*stack_b;
// 	t_stack	*temp_stack_a;
// 	t_stack	*temp_stack_b;
// 	int		i;

// 	stack_a = NULL;
// 	stack_b = NULL;
// 	i = 0;
// 	while (i < 5)
// 	{
// 		create_node(&stack_a, arguments[i]);
// 		create_node(&stack_b, arguments[i]);
// 		i++;
// 	}
// 	printf("Now we rotate A and B!\n\n");
// 	rotate_r(&stack_a, &stack_b);
// 	temp_stack_a = stack_a;
// 	temp_stack_b = stack_b;
// 	printf("\nA:\n");
// 	while (temp_stack_a)
// 	{
// 		printf("%d\n", temp_stack_a->num);
// 		temp_stack_a = temp_stack_a->next;
// 	}
// 	printf("\nB:\n");
// 	while (temp_stack_b)
// 	{
// 		printf("%d\n", temp_stack_b->num);
// 		temp_stack_b = temp_stack_b->next;
// 	}
// 	free_stack(&stack_a);
// 	free_stack(&stack_b);
// 	return (0);
// }

// int reverse_rotate_demo(void)
// {
// 	int		arguments[5] = {4, 3, 1, 2, 5};
// 	t_stack	*stack_a;
// 	t_stack *stack_b;
// 	t_stack	*temp_stack_a;
// 	t_stack *temp_stack_b;
// 	int		i;

// 	stack_a = NULL;
// 	stack_b = NULL;
// 	i = 0;
// 	while (i < 5)
// 	{
// 		create_node(&stack_a, arguments[i]);
// 		create_node(&stack_b, arguments[i]);
// 		i++;
// 	}
// 	printf("Now we reverse rotate A!\n\n");
// 	reverse_rotate_r(&stack_a, &stack_b);
// 	temp_stack_a = stack_a;
// 	temp_stack_b = stack_b;
// 	printf("\nA:\n");
// 	while (temp_stack_a)
// 	{
// 		printf("%d\n", temp_stack_a->num);
// 		temp_stack_a = temp_stack_a->next;
// 	}
// 	printf("\nB:\n");
// 	while (temp_stack_b)
// 	{
// 		printf("%d\n", temp_stack_b->num);
// 		temp_stack_b = temp_stack_b->next;
// 	}
// 	free_stack(&stack_a);
// 	free_stack(&stack_b);
// 	return (0);
// }

// int	main(void)
// {
// 	printf("Original sequence is 4, 3, 1, 2, 5\n");
// 	push_demo();
// 	printf("\n");
// 	swap_demo();
// 	printf("\n");
// 	rotate_demo();
// 	printf("\n");
// 	reverse_rotate_demo();
// }
