/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkinsfat <vkinsfat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 17:13:01 by vkinsfat          #+#    #+#             */
/*   Updated: 2024/04/23 17:40:56 by vkinsfat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>

typedef struct s_stack
{
	int				num;
	struct s_stack	*next;
}	t_stack;

char	**ft_split(char const *s, char c);

int		error_check(int ac, char **av);
int		ft_atoi(const char *str);
int		ft_isdigit(int c);

t_stack	*ft_lstlast(t_stack *lst);

void	create_node(t_stack **stack, int x);
void	free_stack(t_stack **stack);
void	push_a(t_stack **a, t_stack **b);
void	push_b(t_stack **a, t_stack **b);
void	reverse_rotate_a(t_stack **a);
void	reverse_rotate_b(t_stack **b);
void	reverse_rotate_r(t_stack **a, t_stack **b);
void	rotate_a(t_stack **a);
void	rotate_b(t_stack **b);
void	rotate_r(t_stack **a, t_stack **b);
void	swap_a(t_stack **a);
void	swap_b(t_stack **b);
void	swap_s(t_stack **a, t_stack **b);

#endif