/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   existing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitakinsfator <vitakinsfator@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 20:07:03 by vitakinsfat       #+#    #+#             */
/*   Updated: 2024/07/15 19:14:27 by vitakinsfat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void	sleeping(t_philo *philo)
{
	unsigned long long	time;

	time = get_current_time(philo);
	if (time < 0)
		return ;
	pthread_mutex_lock(&philo->print);
	printf("%llu %d is sleeping\n", time, philo->number);
	pthread_mutex_unlock(&philo->print);
	usleep(philo->time_to_sleep);
}

static void	thinking(t_philo *philo)
{
	unsigned long long	time;

	time = get_current_time(philo);
	if (time < 0)
		return ;
	pthread_mutex_lock(&philo->print);
	printf("%llu %d is thinking\n", time, philo->number);
	pthread_mutex_unlock(&philo->print);
}

static void	eating(t_philo *philo)
{
	unsigned long long	time;

	time = 0;
	pthread_mutex_lock(philo->left_fork);
	pthread_mutex_lock(philo->right_fork);
	pthread_mutex_lock(&philo->print);
	time = get_current_time(philo);
	if (time < 0)
		return ;
	printf("%llu %d has taken a fork\n", time, philo->number);
	time = get_current_time(philo);
	if (time < 0)
		return ;
	printf("%llu %d is eating\n", time, philo->number);
	pthread_mutex_unlock(&philo->print);
	usleep(philo->time_to_eat);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
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
	{
		while (1)
		{
			eating(philo);
			sleeping(philo);
			thinking(philo);
		}
	}
	else
	{
		while (i < philo->meals_num)
		{
			eating(philo);
			sleeping(philo);
			thinking(philo);
			i++;
		}
	}
	return (0);
}
