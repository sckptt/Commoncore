/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   observe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkinsfat <vkinsfat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 20:24:26 by vitakinsfat       #+#    #+#             */
/*   Updated: 2024/07/25 21:25:41 by vkinsfat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	check_for_death(t_philo *philos)
{
	int				i;
	struct timeval	tv;
	uint64_t		time;

	i = 0;
	while (i < philos[i].number)
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
