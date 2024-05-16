// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   small_hundred.c                                    :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: vitakinsfator <vitakinsfator@student.42    +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2024/05/16 17:28:35 by vitakinsfat       #+#    #+#             */
// /*   Updated: 2024/05/16 17:48:43 by vitakinsfat      ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "../includes/push_swap.h"
// #include "../Printf/includes/ft_printf.h"

// void	sort_two(t_stack **stack, int isa)
// {
//     if ((*stack)->num > (*stack)->next->num && isa == 1)
//         swap_a(stack);
//     if ((*stack)->num < (*stack)->next->num && isa == 0)
//         swap_b(stack);
// }

// void	sort_three_a(t_stack **stack)
// {
// 	if ((*stack)->num > (*stack)->next->num && (*stack)->next->num < (*stack)->next->next->num
// 		&& (*stack)->num < (*stack)->next->next->num)
// 		swap_a(stack);
//     else if ((*stack)->num < (*stack)->next->num && (*stack)->next->num > (*stack)->next->next->num
// 		&& (*stack)->num > (*stack)->next->next->num)
// 		reverse_rotate_a(stack);
//     else if ((*stack)->num > (*stack)->next->num && (*stack)->next->num > (*stack)->next->next->num
// 		&& (*stack)->num > (*stack)->next->next->num)
// 	{
// 		rotate_a(stack);
// 		swap_a(stack);
// 	}
//     else if ((*stack)->num > (*stack)->next->num && (*stack)->next->num < (*stack)->next->next->num
// 		&& (*stack)->num > (*stack)->next->next->num)
// 		rotate_a(stack);
// 	else if ((*stack)->num < (*stack)->next->num && (*stack)->next->num > (*stack)->next->next->num
// 		&& (*stack)->num < (*stack)->next->next->num)
// 	{
// 		reverse_rotate_a(stack);
// 		swap_a(stack);
// 	}
// }

// void	sort_three_b(t_stack **stack)
// {
// 	if ((*stack)->num > (*stack)->next->num && (*stack)->next->num < (*stack)->next->next->num
// 		&& (*stack)->num < (*stack)->next->next->num)
// 		swap_b(stack);
//     else if ((*stack)->num < (*stack)->next->num && (*stack)->next->num > (*stack)->next->next->num
// 		&& (*stack)->num > (*stack)->next->next->num)
// 		reverse_rotate_b(stack);
//     else if ((*stack)->num > (*stack)->next->num && (*stack)->next->num > (*stack)->next->next->num
// 		&& (*stack)->num > (*stack)->next->next->num)
// 	{
// 		rotate_b(stack);
// 		swap_b(stack);
// 	}
//     else if ((*stack)->num > (*stack)->next->num && (*stack)->next->num < (*stack)->next->next->num
// 		&& (*stack)->num > (*stack)->next->next->num)
// 		rotate_b(stack);
// 	else if ((*stack)->num < (*stack)->next->num && (*stack)->next->num > (*stack)->next->next->num
// 		&& (*stack)->num < (*stack)->next->next->num)
// 	{
// 		reverse_rotate_b(stack);
// 		swap_b(stack);
// 	}
// }

// int len_stack(t_stack *stack)
// {
//     int len;
//     t_stack *temp;

//     len = 0;
//     temp = stack;
//     while (temp)
//     {
//         len++;
//         temp = temp->next;
//     }
//     return (len);
// }

// void	small_sort_100(t_stack **stack, int isa)
// {
// 	if (len_stack(stack) == 2)
// 		sort_two_100(stack, isa);
// 	if (len_stack(stack) == 3 && isa == 1)
// 		sort_three_100_a(stack);
//     if (len_stack(stack) == 3 && isa == 0)
//         sort_three_100_b(stack);
// }
