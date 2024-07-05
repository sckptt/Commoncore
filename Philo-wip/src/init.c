/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitakinsfator <vitakinsfator@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 16:34:05 by vitakinsfat       #+#    #+#             */
/*   Updated: 2024/07/05 16:30:47 by vitakinsfat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

t_common_info	*struct_start(int ac, char **av)
{
	t_common_info	*ph_data;

	ph_data = malloc(sizeof(t_common_info));
	if (!ph_data)
		return (NULL);
	ph_data->number = ft_atoi(av[1]);
	ph_data->time_to_die = ft_atoi(av[2]);
	ph_data->time_to_eat = ft_atoi(av[3]);
	ph_data->time_to_sleep = ft_atoi(av[4]);
	ph_data->forks = NULL;
	ph_data->philos = NULL;
	if (ac == 6)
		ph_data->meals_num = ft_atoi(av[5]);
	else
		ph_data->meals_num = -1;
	return (ph_data);
}

void	create_philos(t_common_info *ph_data)
{
	int	i;

	i = -1;
	ph_data->philos = malloc(sizeof(t_philo) * ph_data->number);
	if (!ph_data->philos)
		return ;
	while (++i < ph_data->number)
	{
		ph_data->philos[i].number = i + 1;
		ph_data->philos[i].time_to_eat = ph_data->time_to_eat;
		ph_data->philos[i].time_to_sleep = ph_data->time_to_sleep;
		ph_data->philos[i].time_to_die = ph_data->time_to_die;
		ph_data->philos[i].meals_num = ph_data->meals_num;
		ph_data->philos[i].when_ate = 0;
		ph_data->philos[i].left_fork = NULL;
		ph_data->philos[i].right_fork = NULL;
		ph_data->philos[i].id = NULL;
	}
}

void	create_forks(t_common_info *ph_data)
{
	int	i;

	i = -1;
	while (++i < ph_data->number)
		pthread_mutex_init(&ph_data->forks[i], NULL);
	i = 0;
	ph_data->philos[0].left_fork = &ph_data->forks[0];
	ph_data->philos[0].right_fork = &ph_data->forks[ph_data->number - 1];
	i++;
	while (i < ph_data->number)
	{
		ph_data->philos[i].left_fork = &ph_data->forks[i];
		ph_data->philos[0].right_fork = &ph_data->forks[i - 1];
		i++;
	}
}
