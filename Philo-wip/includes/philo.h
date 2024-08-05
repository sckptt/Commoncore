/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitakinsfator <vitakinsfator@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 15:38:38 by vitakinsfat       #+#    #+#             */
/*   Updated: 2024/08/05 15:46:41 by vitakinsfat      ###   ########.fr       */
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
# define TIME_ERROR_MSG "Error! The program failed to get time of day!\n"
# define WRONG_NUMBER_OF_ARGS_ERROR_MSG "Error! Wrong number of arguments!\n"
# define OUT_OF_RANGE_ERROR_MSG "Error! Argument is out of range!\n"
# define NON_NUMERIC_ERROR_MSG "Error! Argument is not numeric!\n"
# define THREAD_CREATION_ERROR_MSG "Error! The program failed to create a thread!\n"
# define THREAD_JOIN_ERROR_MSG "Error! The program failed to join a thread!\n"
# define MUTEX_INIT_ERROR_MSG "Error! The program failed to initiate a mutex!\n"
# define SLEEPING_MSG "is sleeping"
# define FORK_MSG "has taken a fork"
# define EATING_MSG "is eating"
# define THINKING_MSG "is thinking"
# define DEATH_MSG "died"

typedef struct s_philo
{
	int				amount;
	int				number;
	int				meals_num;
	int				*if_dead;
	int				food_times;
	int				is_eating;
	uint64_t		start;
	uint64_t		last_meal;
	uint64_t		time_to_die;
	uint64_t		time_to_eat;
	uint64_t		time_to_sleep;
	pthread_t		id;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	print_lock;
	pthread_mutex_t	death_lock;
}	t_philo;

typedef struct s_common_info
{
	int				amount;
	int				if_dead;
	uint64_t		start;
	t_philo			*philos;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print_lock;
	pthread_mutex_t	death_lock;
}	t_common_info;

//data initialization
int			create_forks(t_common_info *ph_data);
int			create_philos(t_common_info *ph_data, int ac, char **av);
int			struct_start(t_common_info *ph_data, char **av);
void		give_forks(t_common_info *ph_data);

//error handling
int			check_args(int ac, char **av);

//philosophers routine
void		*existing(void *param);
void		*observe(void *params);

// utils for philosophers
int			ft_atoi(char *str);
int			ft_isdigit(int c);
long		ft_atol(char *str);
uint64_t	get_current_time(void);
uint64_t	update_time(t_philo *philo);
void		end_programm(t_common_info *ph_data);
void		ft_putstr_fd(char *s, int fd);
void		mutex_destroy(t_common_info *ph_data);
void		print_state(t_philo *philo, char *message);

#endif