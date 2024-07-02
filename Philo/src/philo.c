/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitakinsfator <vitakinsfator@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 15:45:04 by vitakinsfat       #+#    #+#             */
/*   Updated: 2024/07/02 13:49:25 by vitakinsfat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int check_args(char **av)
{
	int i;

	i = 1;
	while (i < 5)
	{
		if (ft_atoi(av[i]) < 1)
		{
			ft_putstr_fd("Error! One of the arguments is less than 1!", 2);
			return (1);
		}
		i++;
	}
	if (av[5])
	{
		if (ft_atoi(av[5]) < 0)
		{
			ft_putstr_fd("Error! Last argument is less than 0!", 2);
			return (1);
		}
	}
	return (0);
}

t_common_info *struct_start(int ac, char **av)
{
	t_common_info *ph_data;

	ph_data = malloc(sizeof(t_common_info));
	if (!ph_data)
		return (NULL);
	ph_data->number_of_philo = ft_atoi(av[1]);
	ph_data->time_to_die = ft_atoi(av[2]);
	ph_data->time_to_eat = ft_atoi(av[3]);
	ph_data->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		ph_data->must_eat = ft_atoi(av[5]);
	else
		ph_data->must_eat = -1;
	pthread_mutex_init(&ph_data->mutex, NULL);
	return (ph_data);
}

int main(int ac, char **av)
{
	t_common_info *ph_data;
	
	if (ac != 5 && ac != 6)
	{
		ft_putstr_fd("Error! Wrong number of arguments!", 2);
		return (1);
	}
	if (check_args(av) != 0)
		return (1);
	ph_data = struct_start(ac, av);
	if (!ph_data)
		return (1);
	printf("%d\n", ph_data->number_of_philo);
	printf("%d\n", ph_data->time_to_die);
	printf("%d\n", ph_data->time_to_eat);
	printf("%d\n", ph_data->time_to_sleep);
	printf("%d\n", ph_data->must_eat);
	free(ph_data);
	return (0);
}