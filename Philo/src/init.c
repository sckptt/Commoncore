/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitakinsfator <vitakinsfator@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 16:34:05 by vitakinsfat       #+#    #+#             */
/*   Updated: 2024/07/02 17:10:06 by vitakinsfat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

t_common_info	*struct_start(int ac, char **av)
{
	t_common_info	*ph_data;

	ph_data = malloc(sizeof(t_common_info));
	if (!ph_data)
		return (NULL);
	ph_data->number_of_philo = ft_atoi(av[1]);
	ph_data->time_to_die = ft_atoi(av[2]);
	ph_data->time_to_eat = ft_atoi(av[3]);
	ph_data->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		ph_data->must_eat = ft_atoi(av[5]);
	else
		ph_data->must_eat = -1;
	pthread_mutex_init(&ph_data->mutex, NULL);
	return (ph_data);
}
