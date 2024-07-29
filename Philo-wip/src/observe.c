/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   observe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitakinsfator <vitakinsfator@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 20:24:26 by vitakinsfat       #+#    #+#             */
/*   Updated: 2024/07/29 17:54:04 by vitakinsfat      ###   ########.fr       */
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
		pthread_mutex_lock(&philos[i].death_lock);
		time = get_current_time();
		if (time - philos[i].last_meal >= philos[i].time_to_die \
			&& philos[i].is_eating == 0)
		{
			*philos[i].if_dead = 1;
			deathtime = (time - philos[i].start) / 1000;
			printf("%llu %d %s\n", deathtime, philos[i].number, DEATH_MSG);
			pthread_mutex_unlock(&philos[i].death_lock);
			return (1);
		}
		pthread_mutex_unlock(&philos[i].death_lock);
		i++;
	}
	return (0);
}

void	*observe(void *params)
{
	t_philo	*philos;

	philos = (t_philo *)params;
	while (1)
	{
		if (check_for_death(philos) == 1)
			break ;
	}
	return (0);
}
