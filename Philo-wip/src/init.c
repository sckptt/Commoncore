/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkinsfat <vkinsfat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 16:34:05 by vitakinsfat       #+#    #+#             */
/*   Updated: 2024/08/20 18:08:49 by vkinsfat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	give_forks(t_philo_data *ph_data)
{
	int	i;

	i = 0;
	if (ph_data->amount == 1)
	{
		ph_data->philos[0].left_m = &ph_data->forks[0];
		ph_data->philos[0].left_f = &ph_data->forks_v[0];
		return ;
	}
	while (i < ph_data->amount)
	{
		ph_data->philos[i].left_m = &ph_data->forks[i];
		ph_data->philos[i].left_f = &ph_data->forks_v[i];
		if (i == 0)
		{
			ph_data->philos[i].right_m = &ph_data->forks[ph_data->amount - 1];
			ph_data->philos[i].right_f = &ph_data->forks_v[ph_data->amount - 1];
		}
		else
		{
			ph_data->philos[i].right_m = &ph_data->forks[i - 1];
			ph_data->philos[i].right_f = &ph_data->forks_v[i - 1];
		}
		i++;
	}
}

void	create_forks(t_philo_data *ph_data)
{
	int	i;

	i = -1;
	while (++i < ph_data->amount)
	{
		ph_data->forks_v[i] = 0;
		pthread_mutex_init(&ph_data->forks[i], NULL);
	}
}

void	create_philos(t_philo_data *ph_data, int ac, char **av)
{
	int	i;

	i = -1;
	while (++i < ph_data->amount)
	{
		ph_data->philos[i].number = i + 1;
		ph_data->philos[i].food_times = 0;
		ph_data->philos[i].is_eating = 0;
		ph_data->philos[i].if_dead = &ph_data->if_dead;
		ph_data->philos[i].finished = &ph_data->finished;
		ph_data->philos[i].time_to_eat = (uint64_t)ft_atoi(av[3]) * 1000;
		ph_data->philos[i].time_to_sleep = (uint64_t)ft_atoi(av[4]) * 1000;
		ph_data->philos[i].time_to_die = (uint64_t)ft_atoi(av[2]) * 1000;
		if (ac == 6)
			ph_data->philos[i].meals_num = ft_atoi(av[5]);
		else if (ac == 5)
			ph_data->philos[i].meals_num = -1;
		ph_data->philos[i].start_time = get_current_time();
		ph_data->philos[i].last_meal = get_current_time();
		ph_data->philos[i].left_m = NULL;
		ph_data->philos[i].right_m = NULL;
		ph_data->philos[i].print_lock = &ph_data->print_lock;
		ph_data->philos[i].death_lock = &ph_data->death_lock;
	}
}

int	struct_start(t_philo_data *ph_data, char **av)
{
	ph_data->amount = ft_atoi(av[1]);
	ph_data->if_dead = 0;
	ph_data->finished = 0;
	ph_data->philos = (t_philo *)malloc(sizeof(t_philo) * ph_data->amount);
	if (!ph_data->philos)
		return (ft_putstr_fd(ALLOCATION_ERROR, 2), 1);
	ph_data->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) \
			* ph_data->amount);
	if (!ph_data->forks)
	{
		free(ph_data->philos);
		return (ft_putstr_fd(ALLOCATION_ERROR, 2), 1);
	}
	ph_data->forks_v = (int *)malloc(sizeof(int) * ph_data->amount);
	if (!ph_data->forks_v)
	{
		free(ph_data->forks);
		free(ph_data->philos);
		return (ft_putstr_fd(ALLOCATION_ERROR, 2), 1);
	}
	pthread_mutex_init(&ph_data->print_lock, NULL);
	pthread_mutex_init(&ph_data->death_lock, NULL);
	return (0);
}

int	fill_the_structs(t_philo_data *ph_data, int ac, char **av)
{
	if (struct_start(ph_data, av) != 0)
		return (1);
	create_philos(ph_data, ac, av);
	create_forks(ph_data);
	give_forks(ph_data);
	return (0);
}
