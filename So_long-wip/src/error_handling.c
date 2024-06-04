/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkinsfat <vkinsfat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 15:29:31 by vitakinsfat       #+#    #+#             */
/*   Updated: 2024/06/04 22:12:26 by vkinsfat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	error_msg(void)
{
	write(2, "Error\n", 6);
	exit(1);
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
				write(2, "Error\n", 6);
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
			write(2, "Error\n", 6);
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
				write(2, "Error\n", 6);
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
	if (data->exit != 1 || data->player != 1 || data->collectible < 1)
	{
		write(2, "Error\n", 6);
		free_data(data);
		exit(1);
	}
	valid_symbols(data);
	rectangle(data);
	surrounded(data);
	valid_exit_collectible(data);
}
