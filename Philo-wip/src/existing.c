/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   existing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkinsfat <vkinsfat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 20:07:03 by vitakinsfat       #+#    #+#             */
/*   Updated: 2024/08/20 18:08:14 by vkinsfat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void	sleep_and_think(t_philo *philo)
{
	print_state(philo, SLEEPING_MSG);
	usleep(philo->time_to_sleep);
	print_state(philo, THINKING_MSG);
	usleep(philo->time_to_sleep / 100);
}

static void	eat(t_philo *philo)
{
	*philo->left_f = 1;
	*philo->right_f = 1;
	print_state(philo, FORK_MSG);
	print_state(philo, EATING_MSG);
	pthread_mutex_lock(philo->death_lock);
	philo->is_eating = 1;
	philo->last_meal = get_current_time();
	pthread_mutex_unlock(philo->death_lock);
	usleep(philo->time_to_eat);
	pthread_mutex_lock(philo->death_lock);
	philo->food_times++;
	philo->is_eating = 0;
	if (philo->food_times == philo->meals_num)
		(*philo->finished)++;
	pthread_mutex_unlock(philo->death_lock);
	*philo->left_f = 0;
	*philo->right_f = 0;
	pthread_mutex_unlock(philo->left_m);
	pthread_mutex_unlock(philo->right_m);
}

static void	living(t_philo *philo)
{
	if (philo->food_times == philo->meals_num)
	{
		usleep(philo->time_to_sleep);
		return ;
	}
	if (philo->left_m < philo->right_m)
	{
		pthread_mutex_lock(philo->left_m);
		pthread_mutex_lock(philo->right_m);
	}
	else
	{
		pthread_mutex_lock(philo->right_m);
		pthread_mutex_lock(philo->left_m);
	}
	eat(philo);
	sleep_and_think(philo);
}

void	*existing(void *param)
{
	t_philo	*philo;

	philo = (t_philo *)param;
	if (philo->number % 2 == 0)
		usleep(philo->time_to_eat / 10);
	while (death_check(philo) != 1)
		living(philo);
	return (0);
}
