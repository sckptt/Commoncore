/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitakinsfator <vitakinsfator@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 15:38:38 by vitakinsfat       #+#    #+#             */
/*   Updated: 2024/07/16 20:29:30 by vitakinsfat      ###   ########.fr       */
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
# include <limits.h>
# include <stdint.h>
# include <inttypes.h>

# define ALLOCATION_ERROR_MSG "Error! The program failed to allocate memory!\n"

typedef struct s_philo
{
	int				amount;
	int				number;
	int				meals_num;
	uint64_t		start;
	uint64_t		last_meal;
	uint64_t		time_to_die;
	uint64_t		time_to_eat;
	uint64_t		time_to_sleep;
	pthread_t		id;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	print;
	pthread_mutex_t dead_lock;
}	t_philo;

typedef struct s_common_info
{
	int				number;
	int				meals_num;
	uint64_t		start;
	uint64_t		time_to_die;
	uint64_t		time_to_eat;
	uint64_t		time_to_sleep;
	t_philo			*philos;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print;
	pthread_mutex_t dead_lock;
}	t_common_info;

//data initialization
int			fill_the_structs(t_common_info *ph_data, int ac, char **av);
int			struct_start(t_common_info *ph_data, int ac, char **av);

//error handling
int			check_args(int ac, char **av);

//philosophers routine
void		*existing(void *param);

// utils for philosophers
int			ft_atoi(char *str);
int			ft_isdigit(int c);
long		ft_atol(char *str);
uint64_t	get_current_time(t_philo *philo);
uint64_t	update_time(t_philo *philo);
void		ft_putstr_fd(char *s, int fd);
void		mutex_destroy(t_common_info *ph_data);
void		print_state(uint64_t time, t_philo *philo, char *message);

#endif