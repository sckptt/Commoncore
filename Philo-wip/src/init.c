/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitakinsfator <vitakinsfator@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 16:34:05 by vitakinsfat       #+#    #+#             */
/*   Updated: 2024/07/29 17:57:16 by vitakinsfat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	struct_start(t_common_info *ph_data, char **av)
{
	ph_data->amount = ft_atoi(av[1]);
	ph_data->if_dead = 0;
	ph_data->start = get_current_time();
	ph_data->forks = NULL;
	ph_data->philos = NULL;
	if (pthread_mutex_init(&ph_data->print_lock, NULL) != 0)
	{
		ft_putstr_fd(MUTEX_INIT_ERROR_MSG, 2);
		return (1);
	}
	if (pthread_mutex_init(&ph_data->death_lock, NULL) != 0)
	{
		ft_putstr_fd(MUTEX_INIT_ERROR_MSG, 2);
		return (1);
	}
	return (0);
}

static void	full_philos(t_common_info *ph_data, int ac, char **av, int i)
{
	ph_data->philos[i].amount = ph_data->amount;
	ph_data->philos[i].number = i + 1;
	ph_data->philos[i].if_dead = &ph_data->if_dead;
	ph_data->philos[i].food_times = 0;
	ph_data->philos[i].is_eating = 0;
	ph_data->philos[i].time_to_eat = (uint64_t)ft_atoi(av[3]) * 1000;
	ph_data->philos[i].time_to_sleep = (uint64_t)ft_atoi(av[4]) * 1000;
	ph_data->philos[i].time_to_die = (uint64_t)ft_atoi(av[2]) * 1000;
	if (ac == 6)
		ph_data->philos[i].meals_num = ft_atoi(av[5]);
	else if (ac == 5)
		ph_data->philos[i].meals_num = -1;
	ph_data->philos[i].last_meal = ph_data->start;
	ph_data->philos[i].start = ph_data->start;
	ph_data->philos[i].left_fork = NULL;
	ph_data->philos[i].right_fork = NULL;
	ph_data->philos[i].print_lock = ph_data->print_lock;
	ph_data->philos[i].death_lock = ph_data->death_lock;
}

int	create_philos(t_common_info *ph_data, int ac, char **av)
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
		full_philos(ph_data, ac, av, i);
	return (0);
}

void	give_forks(t_common_info *ph_data)
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

int	create_forks(t_common_info *ph_data)
{
	int	i;

	i = -1;
	ph_data->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) \
			* ph_data->amount);
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
