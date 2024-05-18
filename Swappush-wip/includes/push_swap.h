/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkinsfat <vkinsfat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 17:13:01 by vkinsfat          #+#    #+#             */
/*   Updated: 2024/05/18 15:40:45 by vkinsfat         ###   ########.fr       */
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
	int				index;
	struct s_stack	*next;
}	t_stack;

typedef struct s_data
{
	int				len_a;
	int				len_b;
	int				allocation;
	int				ac;
	char			**av;
	struct s_stack	*stack_a;
	struct s_stack	*stack_b;
}	t_data;

char	**ft_split(char const *s, char c);

int		argv_len(char **argv);
int		error_check(int ac, char **av);
int		find_position(t_stack *stack, int min);
int		find_min(t_stack *stack);
int		ft_atoi(const char *str);
int		ft_isdigit(int c);
int		sorted_already(t_stack *stack);

t_stack	*copy_stack(t_stack *stack);
t_stack	*ft_lstlast(t_stack *lst);

void	big_sort(t_data **data);
void	delete_node(t_stack **stack, int num);
void	free_data(t_data *data);
void	free_stack(t_stack **stack);
void	get_index(t_data **data);
void	push_a(t_data **data);
void	push_b(t_data **data);
void	reverse_rotate_a(t_stack **a);
void	reverse_rotate_b(t_stack **b);
void	reverse_rotate_r(t_stack **a, t_stack **b);
void	rotate_a(t_stack **a);
void	rotate_b(t_stack **b);
void	rotate_r(t_stack **a, t_stack **b);
void	swap_a(t_stack **a);
void	swap_b(t_stack **b);
void	swap_s(t_stack **a, t_stack **b);
void	small_sort(t_data **data);

#endif