/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitakinsfator <vitakinsfator@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 00:24:37 by vitakinsfat       #+#    #+#             */
/*   Updated: 2024/04/26 21:44:48 by vitakinsfat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../Printf/includes/ft_printf.h"

int	stack_init(t_data *data)
{
	int		i;

	i = 0;
	while (data->av[i])
	{
		create_node(&data->stack_a, ft_atoi(data->av[i]));
		data->len++;
		i++;
	}
	if (data->len <= 10)
		small_sort(&data);
	print_stack(data->stack_a);
	print_stack(data->stack_b);
	free_stack(&data->stack_a);
	free_stack(&data->stack_b);
	free(data);
	return (0);
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
		}
		else
			data->ac = argc - 1;
	}
	error_check(data->ac, data->av);
	stack_init(data);
	return (0);
}
