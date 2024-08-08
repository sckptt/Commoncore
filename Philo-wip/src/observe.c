/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   observe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitakinsfator <vitakinsfator@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 20:24:26 by vitakinsfat       #+#    #+#             */
/*   Updated: 2024/08/08 16:24:39 by vitakinsfat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	death_check(t_philo *philo)
{
	pthread_mutex_lock(&philo->check_lock);
	if (*philo->if_dead == 1)
	{
		pthread_mutex_unlock(&philo->check_lock);
		return (1);
	}
	pthread_mutex_unlock(&philo->check_lock);
	return (0);
}

int	finish_eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->check_lock);
	if (philo->food_times >= philo->meals_num)
	{
		pthread_mutex_unlock(&philo->check_lock);
		return (1);
	}
	pthread_mutex_unlock(&philo->check_lock);
	return (0);
}

void death_msg(t_philo *philo, uint64_t time)
{
	uint64_t	deathtime;
	
	deathtime = (time - philo->start) / 1000;
	pthread_mutex_lock(&philo->print_lock);
	printf("%llu %d %s\n", deathtime, philo->number, DEATH_MSG);
	pthread_mutex_unlock(&philo->print_lock);
}

int	check_for_death(t_philo *philos)
{
	int			i;
	uint64_t	time;

	i = 0;
	while (i < philos[i].amount)
	{
		time = get_current_time();
		pthread_mutex_lock(&philos[i].check_lock);
		if (time - philos[i].last_meal >= philos[i].time_to_die
			&& philos[i].is_eating == 0)
		{
			pthread_mutex_lock(&philos[i].death_lock);
			*philos[i].if_dead = 1;
			pthread_mutex_unlock(&philos[i].death_lock);
			death_msg(&philos[i], time);
			pthread_mutex_unlock(&philos[i].check_lock);
			return (1);
		}
		pthread_mutex_unlock(&philos[i].check_lock);
		i++;
	}
	return (0);
}

int	check_for_finish(t_philo *philos)
{
	int	counter;
	int	i;
	int	amount;

	counter = 0;
	i = 0;
	amount = philos[0].amount;
	if (philos[i].meals_num == -1)
		return (0);
	while (i < amount)
	{
		if (finish_eating(&philos[i]) == 1)
			counter++;
		i++;
	}
	if (counter == amount)
	{
		pthread_mutex_lock(&philos[0].death_lock);
		*philos[0].if_dead = 1;
		pthread_mutex_unlock(&philos[0].death_lock);
		return (1);
	}
	return (0);
}

void	*observe(void *params)
{
	t_philo	*philos;

	philos = (t_philo *)params;
	while (1)
	{
		if (check_for_death(philos) == 1 || check_for_finish(philos) == 1)
			break ;
		//usleep(1000);
	}
	return (0);
}
