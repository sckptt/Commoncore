/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_and_go_home.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkinsfat <vkinsfat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 15:15:56 by vkinsfat          #+#    #+#             */
/*   Updated: 2024/05/18 15:37:07 by vkinsfat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../Printf/includes/ft_printf.h"

void	free_stack(t_stack **stack)
{
	t_stack	*temp;

	if (!*stack)
		return ;
	while (*stack)
	{
		temp = *stack;
		*stack = (*stack)->next;
		free(temp);
	}
	*stack = NULL;
}

void	free_data(t_data *data)
{
	int	i;

	free_stack(&data->stack_a);
	free_stack(&data->stack_b);
	if (data->av != NULL && data->allocation == 1)
	{
		i = 0;
		while (data->av[i])
		{
			free(data->av[i]);
			i++;
		}
		free(data->av);
	}
	free(data);
}
