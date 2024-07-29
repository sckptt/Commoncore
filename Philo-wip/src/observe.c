/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   observe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitakinsfator <vitakinsfator@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 20:24:26 by vitakinsfat       #+#    #+#             */
/*   Updated: 2024/07/29 16:47:41 by vitakinsfat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	check_for_death(t_philo *philos)
{
	int				i;
	struct timeval	tv;
	uint64_t		time;

	i = 0;
	while (i < philos[i].amount)
	{
		pthread_mutex_lock(&philos[i].dead_lock);
		if (gettimeofday(&tv, NULL) != 0)
		{
			pthread_mutex_unlock(&philos[i].dead_lock);
			return (1);
		}
		time = (tv.tv_sec * 1000000) + tv.tv_usec;
		if ((time - philos[i].last_meal) >= philos[i].time_to_die)
		{
			*philos[i].if_dead = 1;
			printf("%d %s\n", philos[i].number, DEATH_MSG);
			print_state(&philos[i], DEATH_MSG);
			pthread_mutex_unlock(&philos[i].dead_lock);
			return (1);
		}
		pthread_mutex_unlock(&philos[i].dead_lock);
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
