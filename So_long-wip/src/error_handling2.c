/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkinsfat <vkinsfat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 18:10:48 by vkinsfat          #+#    #+#             */
/*   Updated: 2024/06/04 21:59:57 by vkinsfat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../Libft/includes/libft.h"

static char	**copy_array(char **array, int width, int height)
{
	int		i;
	int		j;
	char	**copy;

	i = 0;
	copy = (char **)malloc(sizeof(char *) * (height + 1));
	if (!copy)
		return (NULL);
	while (array[i])
	{
		j = 0;
		copy[i] = (char *)malloc(sizeof(char) * (width + 1));
		if (!copy[i])
			return (NULL);
		while (array[i][j])
		{
			copy[i][j] = array[i][j];
			j++;
		}
		array[i][j] = '\0';
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

static void	free_copy(char **copy)
{
	int	i;

	i = 0;
	while (copy[i])
	{
		free(copy[i]);
		i++;
	}
	free(copy);
}

static void	flood_fill(char **map, int y, int x, t_long_data *data)
{
	if (x < 0 || y < 0 || x >= data->map_height || y >= data->map_width)
		return ;
	if (map[x][y] == '1' || map[x][y] == 'X')
		return ;
	map[x][y] = 'X';
	flood_fill(map, y + 1, x, data);
	flood_fill(map, y - 1, x, data);
	flood_fill(map, y, x + 1, data);
	flood_fill(map, y, x - 1, data);
}

static void	valid_check(t_long_data *data, char **copy)
{
	int		i;
	int		j;

	i = 0;
	while (i < data->map_height)
	{
		j = 0;
		while (j < data->map_width)
		{
			if (copy[i][j] == 'C' || copy[i][j] == 'E')
			{
				write(2, "Error\n", 6);
				free_copy(copy);
				free_data(data);
				exit(1);
			}
			j++;
		}
		i++;
	}
}

void	valid_exit_collectible(t_long_data *data)
{
	char	**copy;

	copy = copy_array(data->map, data->map_width, data->map_height);
	if (!copy)
	{
		write(2, "Error\n", 6);
		free_data(data);
		exit(1);
	}
	flood_fill(copy, data->player_position_y, data->player_position_x, data);
	valid_check(data, copy);
	free_copy(copy);
}
