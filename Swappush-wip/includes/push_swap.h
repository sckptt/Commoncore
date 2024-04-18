/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkinsfat <vkinsfat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 17:13:01 by vkinsfat          #+#    #+#             */
/*   Updated: 2024/04/18 19:54:14 by vkinsfat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

typedef struct s_stack
{
	int num;
	struct s_stack *next;
}	t_stack;

int		ft_atoi(const char *str);

char	**ft_split(char const *s, char c);

void push_a(t_stack **a, t_stack **b);
void push_b(t_stack **b, t_stack **a);
void reverse_rotate_a(t_stack **a);
void reverse_rotate_b(t_stack **b);
void reverse_rotate_r(t_stack **a, t_stack **b);
void rotate_a(t_stack **a);
void rotate_b(t_stack **b);
void rotate_r(t_stack **a, t_stack **b);
void swap_a(t_stack **a, t_stack **b);
void swap_b(t_stack **b, t_stack **a);
void swap_s(t_stack **a, t_stack **b);

#endif