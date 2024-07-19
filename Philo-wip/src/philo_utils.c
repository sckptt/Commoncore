/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitakinsfator <vitakinsfator@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 20:08:19 by vitakinsfat       #+#    #+#             */
/*   Updated: 2024/07/19 18:28:10 by vitakinsfat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

uint64_t	get_current_time(t_philo *philo)
{
	uint64_t		time;
	struct timeval	tv;

	if (gettimeofday(&tv, NULL) != 0)
	{
		ft_putstr_fd(TIME_ERROR_MSG, 2);
		return (1);
	}
	time = (tv.tv_sec * 1000000) + tv.tv_usec - philo->start;
	return (time);
}

void	print_state(t_philo *philo, char *message)
{
	uint64_t	time;

	time = get_current_time(philo);
	if (time == 1)
		return ;
	pthread_mutex_lock(&philo->print_lock);
	printf("%llu %d %s\n", time / 1000, philo->number, message);
	pthread_mutex_unlock(&philo->print_lock);
}

void	mutex_destroy(t_common_info *ph_data)
{
	int	i;

	i = -1;
	while (++i < ph_data->amount)
		pthread_mutex_destroy(&ph_data->forks[i]);
	pthread_mutex_destroy(&ph_data->print_lock);
	pthread_mutex_destroy(&ph_data->dead_lock);
	ph_data->forks = NULL;
}

void end_programm(t_common_info *ph_data)
{
	mutex_destroy(ph_data);
	if (ph_data->forks)
	{
		free(ph_data->forks);
		ph_data->forks = NULL;
	}
	if (ph_data->philos)
	{
		free(ph_data->philos);
		ph_data->philos = NULL;
	}
	free(ph_data);
}
