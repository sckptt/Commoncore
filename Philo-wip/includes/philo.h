/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkinsfat <vkinsfat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 15:38:38 by vitakinsfat       #+#    #+#             */
/*   Updated: 2024/08/20 18:08:49 by vkinsfat         ###   ########.fr       */
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

# define ALLOCATION_ERROR "Error! The program failed to allocate memory!\n"
# define TIME_ERROR "Error! The program failed to get time of day!\n"
# define WRONG_NUMBER_OF_ARGS_ERROR "Error! Wrong number of arguments!\n"
# define OUT_OF_RANGE_ERROR "Error! Argument is out of range!\n"
# define NON_NUMERIC_ERROR "Error! Argument is not numeric!\n"
# define THREAD_CREATE_ERROR "Error! The program failed to create a thread!\n"
# define THREAD_JOIN_ERROR "Error! The program failed to join a thread!\n"
# define MUTEX_INIT_ERROR "Error! The program failed to initiate a mutex!\n"
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
	int				food_times;
	int				is_eating;
	int				*if_dead;
	int				*finished;
	int				*left_f;
	int				*right_f;
	uint64_t		start_time;
	uint64_t		last_meal;
	uint64_t		time_to_die;
	uint64_t		time_to_eat;
	uint64_t		time_to_sleep;
	pthread_t		id;
	pthread_mutex_t	*left_m;
	pthread_mutex_t	*right_m;
	pthread_mutex_t	*print_lock;
	pthread_mutex_t	*death_lock;
}	t_philo;

typedef struct s_common_info
{
	int				amount;
	int				if_dead;
	int				finished;
	int				*forks_v;
	uint64_t		start;
	t_philo			*philos;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print_lock;
	pthread_mutex_t	death_lock;
}	t_philo_data;

//data initialization
void		create_forks(t_philo_data *ph_data);
void		create_philos(t_philo_data *ph_data, int ac, char **av);
int			struct_start(t_philo_data *ph_data, char **av);
void		give_forks(t_philo_data *ph_data);

//error handling
int			check_args(int ac, char **av);

//philosophers routine
void		*existing(void *param);
void		*observe(void *params);

// utils for philosophers
int			ft_usleep(uint64_t time);
int			death_check(t_philo *philo);
int			ft_atoi(char *str);
uint64_t	get_current_time(void);
uint64_t	update_time(t_philo *philo);
void		death_msg(t_philo *philo, uint64_t time);
void		end_programm(t_philo_data *ph_data);
void		ft_putstr_fd(char *s, int fd);
void		mutex_destroy(t_philo_data *ph_data);
void		print_state(t_philo *philo, char *message);

#endif