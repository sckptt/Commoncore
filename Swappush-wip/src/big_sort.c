/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitakinsfator <vitakinsfator@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 13:33:25 by vitakinsfat       #+#    #+#             */
/*   Updated: 2024/05/17 18:46:18 by vitakinsfat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../Printf/includes/ft_printf.h"

static void	radix_sort(t_data **data)
{
	int	i;
	int	operations;

	i = 0;
	while (((*data)->ac) >> i)
	{
		operations = (*data)->ac;
		while (operations--)
		{
			if ((*data)->stack_a->index >> i & 1)
				push_b(data);
			else
				rotate_a(&(*data)->stack_a);
		}
		while ((*data)->stack_b)
			push_a(data);
		i++;
		if (sorted_already((*data)->stack_a))
			break ;
	}
}

void	big_sort(t_data **data)
{
	get_index(data);
	radix_sort(data);
}
