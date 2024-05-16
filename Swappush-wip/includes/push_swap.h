/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitakinsfator <vitakinsfator@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 17:13:01 by vkinsfat          #+#    #+#             */
/*   Updated: 2024/05/16 15:44:57 by vitakinsfat      ###   ########.fr       */
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
int		find_max(t_stack *stack);
int		ft_atoi(const char *str);
int		ft_isdigit(int c);
int		get_value(t_data **data);
int		sorted_already(t_stack *stack);

t_stack	*copy_stack(t_stack *stack);
t_stack	*ft_lstlast(t_stack *lst);

void	create_data(t_data **data);
void	create_node(t_stack **stack, int x);
void	delete_node(t_stack **stack, int num);
void	free_stack(t_stack **stack);
void	get_index(t_data **data);
void	hundred_sort(t_data **data);
void	index_init(int counter, t_stack **stack);
void	print_stack(t_stack *stack);
void	print_index(t_stack *stack);
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
void	sort_three(t_data **data);
void	stack_init(t_data *data);

#endif