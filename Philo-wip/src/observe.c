/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   observe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitakinsfator <vitakinsfator@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 20:24:26 by vitakinsfat       #+#    #+#             */
/*   Updated: 2024/08/20 22:03:10 by vitakinsfat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	death_msg(t_philo *philo, uint64_t time)
{
	uint64_t	deathtime;

	deathtime = ((time - philo->start_time) / 1000);
	pthread_mutex_lock(philo->print_lock);
	printf("%llu %d %s\n", deathtime, philo->number, DEATH_MSG);
	pthread_mutex_unlock(philo->print_lock);
}

int	check_for_death(t_philo_data *ph_data)
{
	int			i;
	uint64_t	time;

	i = 0;
	while (i < ph_data->amount)
	{
		pthread_mutex_lock(&ph_data->death_lock);
		time = get_current_time();
		if (time - ph_data->philos[i].last_meal
			>= ph_data->philos[i].time_to_die
			&& ph_data->philos[i].is_eating == 0)
		{
			ph_data->if_dead = 1;
			death_msg(&ph_data->philos[i], time);
			pthread_mutex_unlock(&ph_data->death_lock);
			return (1);
		}
		pthread_mutex_unlock(&ph_data->death_lock);
		i++;
	}
	return (0);
}

int	all_finished(t_philo_data *ph_data)
{
	if (ph_data->philos[0].meals_num == -1)
		return (0);
	pthread_mutex_lock(&ph_data->death_lock);
	if (ph_data->finished == ph_data->amount)
	{
		ph_data->if_dead = 1;
		pthread_mutex_unlock(&ph_data->death_lock);
		return (1);
	}
	pthread_mutex_unlock(&ph_data->death_lock);
	return (0);
}

void	*observe(void *params)
{
	t_philo_data	*ph_data;

	ph_data = (t_philo_data *)params;
	while (1)
	{
		if (check_for_death(ph_data) == 1 || all_finished(ph_data) == 1)
			break ;
		usleep(1000);
	}
	return (params);
}
