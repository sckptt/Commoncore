/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitakinsfator <vitakinsfator@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 15:45:04 by vitakinsfat       #+#    #+#             */
/*   Updated: 2024/07/05 16:31:29 by vitakinsfat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"
#include <inttypes.h>

void	start_the_routine(t_common_info *ph_data)
{
	int	i;

	i = -1;
	while (++i < ph_data->number)
		pthread_create(&ph_data->philos[i].id, NULL, &existing, &ph_data->philos[i]);
	i = -1;
	while (++i < ph_data->number)
		pthread_join(ph_data->philos[i].id, NULL);
}

int	main(int ac, char **av)
{
	t_common_info	*ph_data;

	if (ac != 5 && ac != 6)
	{
		ft_putstr_fd("Error! Wrong number of arguments!\n", 2);
		return (1);
	}
	if (check_args(av) != 0)
		return (1);
	ph_data = struct_start(ac, av);
	if (!ph_data)
		return (1);
	create_philos(ph_data);
	if (!ph_data->philos)
		return (1);
	create_forks(ph_data);
	if (!ph_data->forks)
		return (1);
	free(ph_data);
	return (0);
}
