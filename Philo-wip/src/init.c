/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitakinsfator <vitakinsfator@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 16:34:05 by vitakinsfat       #+#    #+#             */
/*   Updated: 2024/07/19 18:29:15 by vitakinsfat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	struct_start(t_common_info *ph_data, char **av)
{
	struct timeval	tv;

	ph_data->amount = ft_atoi(av[1]);
	if (gettimeofday(&tv, NULL) != 0)
	{
		ft_putstr_fd(TIME_ERROR_MSG, 2);
		return (1);
	}
	ph_data->start = (uint64_t)tv.tv_sec * 1000000 + tv.tv_usec;
	ph_data->forks = NULL;
	ph_data->philos = NULL;
	if (pthread_mutex_init(&ph_data->print_lock, NULL) != 0)
	{
		ft_putstr_fd(MUTEX_INIT_ERROR_MSG, 2);
		return (1);
	}
	if (pthread_mutex_init(&ph_data->dead_lock, NULL) != 0)
	{
		ft_putstr_fd(MUTEX_INIT_ERROR_MSG, 2);
		return (1);
	}
	return (0);
}

static int	create_philos(t_common_info *ph_data, int ac, char **av)
{
	int	i;

	i = -1;
	ph_data->philos = (t_philo *)malloc(sizeof(t_philo) * ph_data->amount);
	if (!ph_data->philos)
	{
		ft_putstr_fd(ALLOCATION_ERROR_MSG, 2);
		return (1);
	}
	while (++i < ph_data->amount)
	{
		ph_data->philos[i].amount = ph_data->amount;
		ph_data->philos[i].number = i + 1;
		ph_data->philos[i].if_dead = 0;
		ph_data->philos[i].food_times = 0;
		ph_data->philos[i].time_to_eat = (uint64_t)ft_atoi(av[3]) * 1000;
		ph_data->philos[i].time_to_sleep = (uint64_t)ft_atoi(av[4]) * 1000;
		ph_data->philos[i].time_to_die = (uint64_t)ft_atoi(av[2]) * 1000;
		if (ac == 6)
			ph_data->philos[i].meals_num = ft_atoi(av[5]);
		else if (ac == 5)
			ph_data->philos[i].meals_num = -1;
		ph_data->philos[i].last_meal = 0;
		ph_data->philos[i].start = ph_data->start;
		ph_data->philos[i].left_fork = NULL;
		ph_data->philos[i].right_fork = NULL;
		ph_data->philos[i].print_lock = ph_data->print_lock;
		ph_data->philos[i].dead_lock = ph_data->dead_lock;
	}
	return (0);
}

static void	give_forks(t_common_info *ph_data)
{
	int	i;

	i = 0;
	ph_data->philos[i].left_fork = &ph_data->forks[i];
	ph_data->philos[i].right_fork = &ph_data->forks[ph_data->amount - 1];
	i++;
	while (i < ph_data->amount)
	{
		ph_data->philos[i].left_fork = &ph_data->forks[i];
		ph_data->philos[i].right_fork = &ph_data->forks[i - 1];
		i++;
	}
}

static int	create_forks(t_common_info *ph_data)
{
	int	i;

	i = -1;
	ph_data->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * ph_data->amount);
	if (!ph_data->forks)
	{
		ft_putstr_fd(ALLOCATION_ERROR_MSG, 2);
		return (1);
	}
	while (++i < ph_data->amount)
	{
		if (pthread_mutex_init(&ph_data->forks[i], NULL) != 0)
		{
			ft_putstr_fd(MUTEX_INIT_ERROR_MSG, 2);
			while (--i >= 0)
				pthread_mutex_destroy(&ph_data->forks[i]);
			return (1);
		}
	}
	return (0);
}

int	fill_the_structs(t_common_info *ph_data, int ac, char **av)
{
	if (struct_start(ph_data, av) != 0)
		return (1);
	if (create_philos(ph_data, ac, av) != 0)
		return (1);
	if (create_forks(ph_data) != 0)
	{
		pthread_mutex_destroy(&ph_data->dead_lock);
		pthread_mutex_destroy(&ph_data->print_lock);
		free(ph_data->forks);
		free(ph_data->philos);
		return (1);
	}
	give_forks(ph_data);
	return (0);
}
