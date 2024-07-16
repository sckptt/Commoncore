/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitakinsfator <vitakinsfator@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 15:45:04 by vitakinsfat       #+#    #+#             */
/*   Updated: 2024/07/16 20:26:09 by vitakinsfat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	start_the_routine(t_common_info *ph_data)
{
	int	i;
	//pthread_t observer;

	i = -1;
	while (++i < ph_data->number)
		pthread_create(&ph_data->philos[i].id, NULL,
			&existing, &ph_data->philos[i]);
	// pthread_create(&observer, NULL, &observe, ph_data->philos);
	i = -1;
	while (++i < ph_data->number)
		pthread_join(ph_data->philos[i].id, NULL);
	// pthread_join(observer, NULL);
}

int	main(int ac, char **av)
{
	t_common_info	*ph_data;

	ph_data = malloc(sizeof(t_common_info));
	if (!ph_data)
		return (1);
	if (check_args(ac, av) != 0)
	{
		free(ph_data);
		return (1);
	}
	if (fill_the_structs(ph_data, ac, av) != 0)
	{
		free(ph_data);
		return (1);
	}
	start_the_routine(ph_data);
	mutex_destroy(ph_data);
	free(ph_data);
	return (0);
}
