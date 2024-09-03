/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkinsfat <vkinsfat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 15:45:04 by vitakinsfat       #+#    #+#             */
/*   Updated: 2024/08/27 18:09:18 by vkinsfat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void	*lone_philo(void *param)
{
	t_philo	*philo;

	philo = (t_philo *)param;
	pthread_mutex_lock(philo->left_m);
	*philo->left_f = 1;
	print_state(philo, FORK_MSG);
	*philo->left_f = 0;
	pthread_mutex_unlock(philo->left_m);
	usleep(philo->time_to_die + 1000);
	return (param);
}

static void	start_the_routine(t_philo_data *ph_data)
{
	int			i;
	pthread_t	observer;

	i = -1;
	if (ph_data->amount == 1)
	{
		pthread_create(&observer, NULL, &observe, ph_data);
		pthread_create(&ph_data->philos[0].id, NULL,
			&lone_philo, &ph_data->philos[0]);
		pthread_join(observer, NULL);
		pthread_join(ph_data->philos[0].id, NULL);
		return ;
	}
	else
	{
		pthread_create(&observer, NULL, &observe, ph_data);
		while (++i < ph_data->amount)
			pthread_create(&ph_data->philos[i].id, NULL,
				&existing, &ph_data->philos[i]);
		i = -1;
		pthread_join(observer, NULL);
		while (++i < ph_data->amount)
			pthread_join(ph_data->philos[i].id, NULL);
	}
}

static int	fill_the_structs(t_philo_data *ph_data, int ac, char **av)
{
	if (struct_start(ph_data, av) != 0)
		return (1);
	create_philos(ph_data, ac, av);
	create_forks(ph_data);
	give_forks(ph_data);
	return (0);
}

int	main(int ac, char **av)
{
	t_philo_data	*ph_data;

	ph_data = malloc(sizeof(t_philo_data));
	if (!ph_data)
		return (ft_putstr_fd(ALLOCATION_ERROR, 2), 1);
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
	end_programm(ph_data);
	return (0);
}
