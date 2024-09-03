/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkinsfat <vkinsfat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 20:08:19 by vitakinsfat       #+#    #+#             */
/*   Updated: 2024/08/20 18:08:49 by vkinsfat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

uint64_t	get_current_time(void)
{
	uint64_t		time;
	struct timeval	tv;

	if (gettimeofday(&tv, NULL) != 0)
	{
		ft_putstr_fd(TIME_ERROR, 2);
		return (1);
	}
	time = (tv.tv_sec * 1000000) + tv.tv_usec;
	return (time);
}

void	print_state(t_philo *philo, char *message)
{
	uint64_t	time;
	uint64_t	millitime;

	time = get_current_time();
	if (time == 1)
		return ;
	if (death_check(philo) == 1)
		return ;
	millitime = (time - philo->start_time) / 1000;
	pthread_mutex_lock(philo->print_lock);
	printf("%lu %d %s\n", millitime, philo->number, message);
	pthread_mutex_unlock(philo->print_lock);
}

void	end_programm(t_philo_data *ph_data)
{
	int	i;

	i = -1;
	while (++i < ph_data->amount)
		pthread_mutex_destroy(&ph_data->forks[i]);
	pthread_mutex_destroy(&ph_data->print_lock);
	pthread_mutex_destroy(&ph_data->death_lock);
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
	if (ph_data->forks_v)
	{
		free(ph_data->forks_v);
		ph_data->forks = NULL;
	}
	free(ph_data);
}

int	death_check(t_philo *philo)
{
	pthread_mutex_lock(philo->death_lock);
	if (*philo->if_dead == 1)
	{
		pthread_mutex_unlock(philo->death_lock);
		return (1);
	}
	pthread_mutex_unlock(philo->death_lock);
	return (0);
}

// int	ft_usleep(uint64_t time)
// {
// 	uint64_t	start;

// 	start = get_current_time();
// 	while ((get_current_time() - start) < time)
// 		usleep(time / 10);
// 	return (0);
// }
