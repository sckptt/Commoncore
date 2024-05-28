/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitakinsfator <vitakinsfator@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 20:50:06 by vitakinsfat       #+#    #+#             */
/*   Updated: 2024/05/28 19:46:28 by vitakinsfat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	create_data(t_long_data **data)
{
	t_long_data	*node;

	node = malloc(sizeof(t_long_data));
	if (!node)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	node->map_height = 0;
	node->map_width = 0;
	node->player_position_x = 0;
	node->player_position_y = 0;
	node->player = 0;
	node->exit = 0;
	node->collectible = 0;
	node->steps = 0;
	node->map = NULL;
	*data = node;
}

void	free_data(t_long_data **data)
{
	int	i;

	i = 0;
	while ((*data)->map[i])
	{
		free((*data)->map[i]);
		i++;
	}
	free((*data)->map);
	free(*data);
}

int	count_lines(char **av)
{
	int		fd;
	int		counter;
	char	*line;

	counter = 0;
	line = NULL;
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
	{
		write(1, "Error\n", 6);
		exit(1);
	}
	while ((line = get_next_line(fd)) != NULL)
	{
		counter++;
		free(line);
	}
	close(fd);
	return (counter);
}

int	get_map(t_long_data **data, char **av)
{
	int		lines;
	int		fd;
	int		i;

	fd = open(av[1], O_RDONLY);
	if (fd == -1)
	{
		write(1, "Error\n", 6);
		exit(1);
	}
	lines = count_lines(av);
	(*data)->map = (char **)malloc(sizeof(char *) * (lines + 1));
	if (!(*data)->map)
	{
		write(1, "Error\n", 6);
		exit(1);
	}
	i = 0;
	while (i < lines)
	{
		(*data)->map[i] = get_next_line(fd);
		i++;
	}
	(*data)->map[i] = NULL;
	close(fd);
	return (0);
}

int	main(int ac, char **av)
{
	t_long_data	*data;
	int			i;

	if (ac != 2)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	create_data(&data);
	get_map(&data, av);
	i = 0;
	while (data->map[i])
	{
		printf("%s\n", data->map[i]);
		i++;
	}
	error_handling(&data);
	return (0);
}
