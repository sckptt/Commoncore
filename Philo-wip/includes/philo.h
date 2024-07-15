/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitakinsfator <vitakinsfator@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 15:38:38 by vitakinsfat       #+#    #+#             */
/*   Updated: 2024/07/15 15:51:23 by vitakinsfat      ###   ########.fr       */
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

typedef struct s_philo
{
	int				number;
	int				meals_num;
	uint64_t		when_ate;
	uint64_t		time_to_die;
	uint64_t		time_to_eat;
	uint64_t		time_to_sleep;
	pthread_t		id;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
}	t_philo;

typedef struct s_common_info
{
	int					number;
	int					meals_num;
	unsigned long long	start;
	uint64_t			time_to_die;
	uint64_t			time_to_eat;
	uint64_t			time_to_sleep;
	t_philo				*philos;
	pthread_mutex_t		*forks;
}	t_common_info;

// utils for philosophers
int		ft_atoi(char *str);
int		ft_isdigit(int c);
long	ft_atol(char *str);
void	ft_putstr_fd(char *s, int fd);

//data initialization
int		fill_the_structs(t_common_info *ph_data, int ac, char **av);
int		struct_start(t_common_info *ph_data, int ac, char **av);

//error handling
int		check_args(int ac, char **av);

//philosophers routine
void	*existing(void *param);
void	mutex_destroy(t_common_info *ph_data);

#endif