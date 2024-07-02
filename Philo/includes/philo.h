/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitakinsfator <vitakinsfator@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 15:38:38 by vitakinsfat       #+#    #+#             */
/*   Updated: 2024/07/02 17:11:50 by vitakinsfat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_philo
{
	int				when_ate;
	int				time_to_die;
	pthread_t		id;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
}	t_philo;

typedef struct s_common_info
{
	int				number_of_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat;
	pthread_mutex_t	mutex;
}	t_common_info;

// utils for philosophers
int				ft_atoi(char *str);
void			ft_putstr_fd(char *s, int fd);
int				ft_isdigit(int c);

t_common_info	*struct_start(int ac, char **av);

int				check_args(char **av);

#endif