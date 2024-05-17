/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitakinsfator <vitakinsfator@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 13:33:25 by vitakinsfat       #+#    #+#             */
/*   Updated: 2024/05/17 16:31:37 by vitakinsfat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../Printf/includes/ft_printf.h"

void radix_sort(t_data **data)
{
    int i;
    int operations;

    i = 0;
    while (((*data)->ac - 1) >> i)
    {
        operations = (*data)->ac - 1;
        while (operations--)
        {
            if ((*data)->stack_a->index >> i & 1)
                push_b(data);
            else if ((*data)->stack_a)
                rotate_a(&(*data)->stack_a);
        }
        while ((*data)->stack_b)
            push_a(data);
        i++;
    }
}

void    big_sort(t_data **data)
{
    get_index(data);
    radix_sort(data);
    // print_stack((*data)->stack_a);
    // print_index((*data)->stack_a);
}
