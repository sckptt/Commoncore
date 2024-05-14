/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitakinsfator <vitakinsfator@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 00:24:37 by vitakinsfat       #+#    #+#             */
/*   Updated: 2024/05/14 18:40:08 by vitakinsfat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../Printf/includes/ft_printf.h"

void	push_swap(t_data *data)
{
	stack_init(data);
	if (data->ac <= 10)
		small_sort(&data);
	if (data-> ac > 10 && data->ac <= 100)
		hundred_sort(&data);
	// if (data->ac <= 500)
	// 	five_hundred_sort(&data);
	//print_stack(data->stack_a);
	//print_stack(data->stack_b);
	free_stack(&data->stack_a);
	free_stack(&data->stack_b);
	free(data);
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
	push_swap(data);
	return (0);
}
