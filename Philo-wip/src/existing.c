/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   existing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitakinsfator <vitakinsfator@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 20:07:03 by vitakinsfat       #+#    #+#             */
/*   Updated: 2024/07/05 16:34:07 by vitakinsfat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void	sleeping(t_philo *philo)
{
	printf("%d is sleeping\n", philo->number);
	usleep(philo->time_to_sleep);
}

static void	thinking(t_philo *philo)
{
	printf("%d is thinking\n", philo->number);
}

static void	eating(t_philo *philo)
{
	if (philo->number % 2 == 0)
		sleep(1);
	printf("%d has taken a fork\n", philo->number);
	printf("%d is eating\n", philo->number);
	usleep(philo->time_to_eat);
}

void	*existing(void *param)
{
	int		i;
	t_philo	*philo;

	i = 0;
	philo = (t_philo *)param;
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
}
