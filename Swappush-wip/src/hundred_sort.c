/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hundred_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitakinsfator <vitakinsfator@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 16:32:44 by vitakinsfat       #+#    #+#             */
/*   Updated: 2024/05/16 19:50:55 by vitakinsfat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../Printf/includes/ft_printf.h"

void    sorting_preparation(t_data **data)
{
    int value;
	
    value = (*data)->ac / 2;
    while ((*data)->len_a > value)
    {
		if ((*data)->stack_a->index < value)
			push_b(data);
		else if (((*data)->stack_a->index >= value) && ((*data)->len_b > 2) && ((*data)->stack_b->index < (*data)->stack_b->next->index))
			rotate_r(&(*data)->stack_a, &(*data)->stack_b);
		else
			rotate_a(&(*data)->stack_a);
	}
}

// void push_back(t_data **data)
// {
//  int max;
//  int position;

//  while ((*data)->stack_b)
//  {
//      max = find_max((*data)->stack_b);
//      position = find_position((*data)->stack_b, max);
//      if ((*data)->stack_a->index - (*data)->stack_b->index == 1)
//          push_a(data);
//      else
//      {
//          if (position < (*data)->ac / 2)
//              rotate_b(&(*data)->stack_b);
//          else if (position >= (*data)->ac / 2)
//              reverse_rotate_b(&(*data)->stack_b);
//      }
//  }
// }

void    hundred_sort(t_data **data)
{
    get_index(data);
    sorting_preparation(data);
    print_stack((*data)->stack_a);
    print_stack((*data)->stack_b);
    //push_back(data);
}

