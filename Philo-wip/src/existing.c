/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   existing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitakinsfator <vitakinsfator@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 20:07:03 by vitakinsfat       #+#    #+#             */
/*   Updated: 2024/08/08 16:24:02 by vitakinsfat      ###   ########.fr       */
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
	if (philo->amount == 1)
		return ;
	pthread_mutex_lock(philo->left_fork);
	pthread_mutex_lock(philo->right_fork);
	print_state(philo, FORK_MSG);
	print_state(philo, EATING_MSG);
	pthread_mutex_lock(&philo->check_lock);
	philo->food_times++;
	philo->is_eating = 1;
	pthread_mutex_unlock(&philo->check_lock);
	usleep(philo->time_to_eat);
	pthread_mutex_lock(&philo->check_lock);
	philo->last_meal = get_current_time();
	philo->is_eating = 0;
	pthread_mutex_unlock(&philo->check_lock);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

static void	infinite_loop(t_philo *philo)
{
	while (death_check(philo) != 1)
	{
		eating(philo);
		sleeping(philo);
		thinking(philo);
	}
}

void	*existing(void *param)
{
	t_philo	*philo;

	philo = (t_philo *)param;
	if (philo->number % 2 == 0)
		usleep(philo->time_to_eat / 2);
	if (philo->meals_num == -1)
		infinite_loop(philo);
	else
	{
		while (death_check(philo) != 1)
		{
			if (finish_eating(philo) == 1)
				return (0);
			eating(philo);
			sleeping(philo);
			thinking(philo);
		}
	}
	return (0);
}
