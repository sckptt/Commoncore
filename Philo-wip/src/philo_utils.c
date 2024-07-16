/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitakinsfator <vitakinsfator@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 20:08:19 by vitakinsfat       #+#    #+#             */
/*   Updated: 2024/07/16 20:20:07 by vitakinsfat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

uint64_t	get_current_time(t_philo *philo)
{
	uint64_t		time;
	struct timeval	tv;

	if (gettimeofday(&tv, NULL) != 0)
		return (1);
	time = (tv.tv_sec * 1000000) + tv.tv_usec - philo->start;
	return (time);
}

void print_state(uint64_t time, t_philo *philo, char *message)
{
	pthread_mutex_lock(&philo->print);
	printf("%llu %d %s\n", time, philo->number, message);
	pthread_mutex_unlock(&philo->print);
}

void	mutex_destroy(t_common_info *ph_data)
{
	int	i;

	i = -1;
	while (++i < ph_data->number)
		pthread_mutex_destroy(&ph_data->forks[i]);
	pthread_mutex_destroy(&ph_data->print);
	//pthread_mutex_destroy(&ph_data->dead_lock);
	free(ph_data->forks);
	ph_data->forks = NULL;
}
