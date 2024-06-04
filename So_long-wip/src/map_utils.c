/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkinsfat <vkinsfat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 16:14:39 by vitakinsfat       #+#    #+#             */
/*   Updated: 2024/06/03 22:34:53 by vkinsfat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

size_t	long_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0' && str[i] != '\n' && str[i] != '\r')
		i++;
	return (i);
}

static void	if_p(t_long_data *data, int i, int j)
{
	data->player++;
	data->player_position_x = i;
	data->player_position_y = j;
}

static void	if_e(t_long_data *data, int i, int j)
{
	data->exit++;
	data->exit_x = i;
	data->exit_y = j;
}

void	map_analysis(t_long_data *data)
{
	int	i;
	int	j;

	i = 0;
	data->map_width = long_strlen(data->map[0]);
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'P')
				if_p(data, i, j);
			else if (data->map[i][j] == 'E')
				if_e(data, i, j);
			else if (data->map[i][j] == 'C')
				data->collectible++;
			j++;
		}
		i++;
		data->map_height++;
	}
}
