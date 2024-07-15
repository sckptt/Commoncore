/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timey_wimey_stuff.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitakinsfator <vitakinsfator@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 16:31:16 by vitakinsfat       #+#    #+#             */
/*   Updated: 2024/07/15 18:56:03 by vitakinsfat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

unsigned long long	get_current_time(t_philo *philo)
{
	unsigned long long	time;
	unsigned long long	timestamp;
	struct timeval		tv;

	if (gettimeofday(&tv, NULL) != 0)
		return (-1);
	time = (tv.tv_sec * 1000000) + tv.tv_usec;
	timestamp = time - philo->start;
	return (timestamp);
}
