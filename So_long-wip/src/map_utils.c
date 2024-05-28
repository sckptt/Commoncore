/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitakinsfator <vitakinsfator@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 16:14:39 by vitakinsfat       #+#    #+#             */
/*   Updated: 2024/05/28 19:46:12 by vitakinsfat      ###   ########.fr       */
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

void	map_analysis(t_long_data **data)
{
	int	i;
	int	j;

	i = 0;
	(*data)->map_width = long_strlen((*data)->map[0]);
	while ((*data)->map[i])
	{
		j = 0;
		while ((*data)->map[i][j])
		{
			if ((*data)->map[i][j] == 'P')
			{
				(*data)->player++;
				(*data)->player_position_x = i;
				(*data)->player_position_y = j;
			}
			else if ((*data)->map[i][j] == 'E')
				(*data)->exit++;
			else if ((*data)->map[i][j] == 'C')
				(*data)->collectible++;
			j++;
		}
		i++;
		(*data)->map_height++;
	}
	printf("\nData:\n");
	printf("height is: %d\n", (*data)->map_height);
	printf("width is: %d\n", (*data)->map_width);
	printf("number of exits is: %d\n", (*data)->exit);
	printf("number of players is: %d\n", (*data)->player);
	printf("number of collectible is: %d\n", (*data)->collectible);
	printf("player position is: x = %d, y = %d\n", (*data)->player_position_x, (*data)->player_position_y);
}
