/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitakinsfator <vitakinsfator@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 00:24:37 by vitakinsfat       #+#    #+#             */
/*   Updated: 2024/05/17 18:55:27 by vitakinsfat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../Printf/includes/ft_printf.h"

static void	create_node(t_stack **stack, int x)
{
	t_stack	*node;
	t_stack	*last;

	last = *stack;
	node = malloc(sizeof(t_stack));
	if (!node)
	{
		ft_printf("%s", "Error\n");
		exit(1);
	}
	node->num = x;
	node->index = 0;
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

static void	stack_init(t_data *data)
{
	int		i;

	i = 0;
	while (data->av[i])
	{
		create_node(&data->stack_a, ft_atoi(data->av[i]));
		data->len_a++;
		i++;
	}
}

static void	create_data(t_data **data)
{
	t_data	*node;

	node = malloc(sizeof(t_data));
	if (!node)
	{
		ft_printf("%s", "Error\n");
		exit(1);
	}
	node->stack_a = NULL;
	node->stack_b = NULL;
	node->allocation = 0;
	node->len_a = 0;
	node->len_b = 0;
	node->ac = 0;
	node->av = NULL;
	*data = node;
}

static void	push_swap(t_data *data)
{
	stack_init(data);
	if (data->ac <= 10)
		small_sort(&data);
	if (data->ac > 10 && data->ac <= 500)
		big_sort(&data);
	free_data(data);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	create_data(&data);
	if (argc < 2)
		exit(0);
	if (argc > 1)
	{
		data->av = argv + 1;
		if (argc == 2)
		{
			data->av = ft_split(argv[1], ' ');
			data->ac = argv_len(data->av);
			data->allocation = 1;
		}
		else
			data->ac = argc - 1;
	}
	error_check(data->ac, data->av);
	push_swap(data);
	return (0);
}
