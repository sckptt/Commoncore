/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   observe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitakinsfator <vitakinsfator@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 20:24:26 by vitakinsfat       #+#    #+#             */
/*   Updated: 2024/08/05 19:39:42 by vitakinsfat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	check_for_death(t_philo *philos)
{
	int			i;
	uint64_t	time;
	uint64_t	deathtime;

	i = 0;
	while (i < philos[i].amount)
	{
		if (finish_eating(&philos[i]) == 1)
			i++;
		pthread_mutex_lock(&philos[i].death_lock);
		time = get_current_time();
		if (time - philos[i].last_meal >= philos[i].time_to_die && philos[i].is_eating == 0)
		{
			*philos[i].if_dead = 1;
			deathtime = (time - philos[i].start) / 1000;
			pthread_mutex_lock(&philos[i].print_lock);
			printf("%llu %d %s\n", deathtime, philos[i].number, DEATH_MSG);
			pthread_mutex_unlock(&philos[i].print_lock);
			pthread_mutex_unlock(&philos[i].death_lock);
			return (1);
		}
		pthread_mutex_unlock(&philos[i].death_lock);
		i++;
	}
	return (0);
}

int check_for_finish(t_philo *philos)
{
	int counter;
	int i;
	int amount;

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
	return(0);
}

void	*observe(void *params)
{
	t_philo	*philos;

	philos = (t_philo *)params;
	while (1)
	{
		if (check_for_death(philos) == 1 || check_for_finish(philos) == 1)
			break ;
	}
	return (0);
}
