/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitakinsfator <vitakinsfator@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 15:38:38 by vitakinsfat       #+#    #+#             */
/*   Updated: 2024/07/05 18:12:02 by vitakinsfat      ###   ########.fr       */
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
	int				number;
	int				meals_num;
	useconds_t		when_ate;
	useconds_t		time_to_die;
	useconds_t		time_to_eat;
	useconds_t		time_to_sleep;
	pthread_t		id;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
}	t_philo;

typedef struct s_common_info
{
	int					number;
	int					meals_num;
	unsigned long long	program_start;
	useconds_t			time_to_die;
	useconds_t			time_to_eat;
	useconds_t			time_to_sleep;
	t_philo				*philos;
	pthread_mutex_t		*forks;
}	t_common_info;

// utils for philosophers
int				ft_atoi(char *str);
void			ft_putstr_fd(char *s, int fd);
int				ft_isdigit(int c);

//data initialization
t_common_info	*struct_start(int ac, char **av);
void			create_philos(t_common_info *ph_data);
void			create_forks(t_common_info *ph_data);

int				check_args(char **av);

void			*existing(void *param);

#endif