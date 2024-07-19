/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   existing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitakinsfator <vitakinsfator@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 20:07:03 by vitakinsfat       #+#    #+#             */
/*   Updated: 2024/07/19 17:00:33 by vitakinsfat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void	sleeping(t_philo *philo)
{
	print_state(philo, SLEEPING_MSG);
	usleep(philo->time_to_sleep);
}

static void	thinking(t_philo *philo)
{
	print_state(philo, THINKING_MSG);
}

static void	eating(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	pthread_mutex_lock(philo->right_fork);
	print_state(philo, FORK_MSG);
	print_state(philo, EATING_MSG);
	pthread_mutex_lock(&philo->dead_lock);
	philo->last_meal = get_current_time(philo);
	philo->food_times++;
	pthread_mutex_unlock(&philo->dead_lock);
	usleep(philo->time_to_eat);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

static void	infinite_loop(t_philo *philo)
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
	t_philo	*philo;

	philo = (t_philo *)param;
	if (philo->number % 2 == 0)
		usleep(1000);
	if (philo->meals_num == -1)
		infinite_loop(philo);
	else
	{
		while (philo->food_times < philo->meals_num && philo->if_dead)
		{
			thinking(philo);
			eating(philo);
			sleeping(philo);
		}
	}
	return (0);
}
