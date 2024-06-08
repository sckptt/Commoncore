/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkinsfat <vkinsfat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 15:29:31 by vitakinsfat       #+#    #+#             */
/*   Updated: 2024/06/08 16:04:58 by vkinsfat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../Libft/includes/libft.h"

int	check_filename(const char *arg)
{
	int	i;

	i = ft_strlen(arg) - 1;
	if (arg[i] != 'r' || arg[i - 1] != 'e'
		|| arg[i - 2] != 'b'
		|| arg[i - 3] != '.')
		return (0);
	return (1);
}

static void	valid_symbols(t_long_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->map[i])
	{
		while (data->map[i][j])
		{
			if (data->map[i][j] != 'P' && data->map[i][j] != 'E'
			&& data->map[i][j] != 'C' && data->map[i][j] != '0'
			&& data->map[i][j] != '1')
			{
				ft_putstr_fd(EXTRA_SYMBOLS_MSG, 2);
				free_data(data);
				exit(1);
			}
			j++;
		}
		j = 0;
		i++;
	}
}

static void	rectangle(t_long_data *data)
{
	int	len;
	int	i;

	i = 1;
	while (data->map[i])
	{
		len = long_strlen(data->map[i]);
		if (len != data->map_width)
		{
			ft_putstr_fd(NO_RECTANGLE_MSG, 2);
			free_data(data);
			exit(1);
		}
		i++;
	}
}

static void	surrounded(t_long_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->map[i])
	{
		while (data->map[i][j])
		{
			if (data->map[0][j] != '1' || data->map[i][0] != '1'
			|| data->map[data->map_height - 1][j] != '1'
			|| data->map[i][data->map_width - 1] != '1')
			{
				ft_putstr_fd(NO_WALL_MSG, 2);
				free_data(data);
				exit(1);
			}
			j++;
		}
		j = 0;
		i++;
	}
}

void	error_handling(t_long_data *data)
{
	map_analysis(data);
	if (data->num_exit != 1)
	{
		ft_putstr_fd(WRONG_EXIT_MSG, 2);
		free_data(data);
		exit(1);
	}
	if (data->num_player != 1)
	{
		ft_putstr_fd(WRONG_PLAYER_MSG, 2);
		free_data(data);
		exit(1);
	}
	if (data->num_collectible < 1)
	{
		ft_putstr_fd(NO_COLLECTIBLES_MSG, 2);
		free_data(data);
		exit(1);
	}
	valid_symbols(data);
	rectangle(data);
	surrounded(data);
	valid_exit_collectible(data);
}
