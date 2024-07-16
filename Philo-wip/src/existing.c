/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   existing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitakinsfator <vitakinsfator@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 20:07:03 by vitakinsfat       #+#    #+#             */
/*   Updated: 2024/07/16 20:19:23 by vitakinsfat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"



static void	sleeping(t_philo *philo)
{
	uint64_t	time;

	time = get_current_time(philo);
	if (time == 1)
		return ;
	print_state(time / 1000, philo, "is sleeping");
	usleep(philo->time_to_sleep);
}

static void	thinking(t_philo *philo)
{
	uint64_t	time;

	time = get_current_time(philo);
	if (time == 1)
		return ;
	print_state(time / 1000, philo, "is thinking");
}

static void	eating(t_philo *philo)
{
	uint64_t	time;

	pthread_mutex_lock(philo->left_fork);
	pthread_mutex_lock(philo->right_fork);
	time = get_current_time(philo);
	if (time == 1)
	{
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
		return ;
	}
	print_state(time / 1000, philo, "has taken a fork");
	time = get_current_time(philo);
	if (time == 1)
	{
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
		return ;
	}
	print_state(time / 1000, philo, "is eating");
	philo->last_meal = get_current_time(philo);
	usleep(philo->time_to_eat);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

static void infinite_loop(t_philo *philo)
{
	while (1)
	{
		thinking(philo);
		eating(philo);
		sleeping(philo);
	}
}

void	*existing(void *param)
{
	int		i;
	t_philo	*philo;

	i = 0;
	philo = (t_philo *)param;
	if (philo->number % 2 == 0)
		usleep(1000);
	if (philo->meals_num == -1)
		infinite_loop(philo);
	else
	{
		while (i < philo->meals_num)
		{
			thinking(philo);
			eating(philo);
			sleeping(philo);
			i++;
		}
	}
	return (0);
}
