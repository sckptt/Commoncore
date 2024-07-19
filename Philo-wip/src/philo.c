/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitakinsfator <vitakinsfator@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 15:45:04 by vitakinsfat       #+#    #+#             */
/*   Updated: 2024/07/19 18:16:49 by vitakinsfat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int join_threads(t_common_info *ph_data, pthread_t observer)
{
	int i;

	i = -1;
	if (pthread_join(observer, NULL) != 0)
	{
		ft_putstr_fd(THREAD_JOIN_ERROR_MSG, 2);
		return (1);
	}
	while (++i < ph_data->amount)
	{
		if (pthread_join(ph_data->philos[i].id, NULL) != 0)
		{
			ft_putstr_fd(THREAD_JOIN_ERROR_MSG, 2);
			return (1);
		}
	}
	return (0);
}

static int	start_the_routine(t_common_info *ph_data)
{
	int			i;
	pthread_t	observer;

	i = -1;
	if (pthread_create(&observer, NULL, &observe, ph_data->philos) != 0)
	{
		ft_putstr_fd(THREAD_CREATION_ERROR_MSG, 2);
		return (1);
	}
	while (++i < ph_data->amount)
		if (pthread_create(&ph_data->philos[i].id, NULL,
			&existing, &ph_data->philos[i]) != 0)
		{
			ft_putstr_fd(THREAD_CREATION_ERROR_MSG, 2);
			return (1);
		}
	if (join_threads(ph_data, observer) == 1)
		return (1);
	return (0);
}

int	main(int ac, char **av)
{
	t_common_info	*ph_data;

	ph_data = malloc(sizeof(t_common_info));
	if (!ph_data)
	{
		ft_putstr_fd(ALLOCATION_ERROR_MSG, 2);
		return (1);
	}
	if (check_args(ac, av) != 0)
	{
		free(ph_data);
		return (1);
	}
	if (fill_the_structs(ph_data, ac, av) != 0)
	{
		free(ph_data);
		return (1);
	}
	if (start_the_routine(ph_data) != 0)
	{
		end_programm(ph_data);
		return (1);
	}
	end_programm(ph_data);
	return (0);
}
