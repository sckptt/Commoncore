/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   observe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitakinsfator <vitakinsfator@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 20:24:26 by vitakinsfat       #+#    #+#             */
/*   Updated: 2024/07/16 20:25:16 by vitakinsfat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

// int check_for_death(t_philo *philos)
// {
// 	int i;
// 	struct timeval tv;
// 	u_int64_t time;

// 	i = 0;
// 	while (i < philos[i].number)
// 	{
// 		if (gettimeofday(&tv, NULL) != 0)
// 			return (1);
// 		time = (tv.tv_sec * 1000000) + tv.tv_usec - philos[i].start;
// 		if (time - philos[i].last_meal >= philos[i].time_to_die)
// 			return (1);
// 		else
// 			i++;
// 	}
// 	return (0);
// }

// void *observe(void *params)
// {
// 	t_philo *philos;
	
// 	philos = (t_philo *)params;
// 	while (1)
// 	{
// 		if (check_for_death(philos) == 1)
// 		 	break ;
// 	}
// 	return (0);
// }
