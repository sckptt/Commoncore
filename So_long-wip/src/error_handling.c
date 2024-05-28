/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitakinsfator <vitakinsfator@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 15:29:31 by vitakinsfat       #+#    #+#             */
/*   Updated: 2024/05/28 19:44:54 by vitakinsfat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	valid_symbols(t_long_data **data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while ((*data)->map[i])
	{
		while ((*data)->map[i][j])
		{
			if ((*data)->map[i][j] != 'P' && (*data)->map[i][j] != 'E'
			&& (*data)->map[i][j] != 'C' && (*data)->map[i][j] != '0'
			&& (*data)->map[i][j] != '1')
			{
				printf("Extra symbols error!");
				free_data(data);
				exit(1);
			}
			j++;
		}
		j = 0;
		i++;
	}
}

static void	rectangle(t_long_data **data)
{
	int	len;
	int	i;

	i = 1;
	while ((*data)->map[i])
	{
		len = long_strlen((*data)->map[i]);
		if (len != (*data)->map_width)
		{
			printf("No rectangle error!");
			free_data(data);
			exit(1);
		}
		i++;
	}
}

static void	surrounded(t_long_data **data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while ((*data)->map[i])
	{
		while ((*data)->map[i][j])
		{
			if ((*data)->map[0][j] != '1' || (*data)->map[i][0] != '1'
			|| (*data)->map[(*data)->map_height - 1][j] != '1'
			|| (*data)->map[i][(*data)->map_width - 1] != '1')
			{
				printf("No wall error!");
				free_data(data);
				exit(1);
			}
			j++;
		}
		j = 0;
		i++;
	}
}

void	error_handling(t_long_data **data)
{
	map_analysis(data);
	if ((*data)->exit != 1 || (*data)->player != 1 || (*data)->collectible < 1)
	{
		printf("Exit/player/collectible error!");
		free_data(data);
		exit(1);
	}
	valid_symbols(data);
	rectangle(data);
	surrounded(data);
}
