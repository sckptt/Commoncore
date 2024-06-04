/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkinsfat <vkinsfat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 20:50:06 by vitakinsfat       #+#    #+#             */
/*   Updated: 2024/06/04 22:12:06 by vkinsfat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../Libft/includes/libft.h"

void	fill_node(t_long_data *node)
{
	node->map_height = 0;
	node->map_width = 0;
	node->player_position_x = 0;
	node->player_position_y = 0;
	node->player = 0;
	node->exit = 0;
	node->exit_x = 0;
	node->exit_y = 0;
	node->collectible = 0;
	node->steps = 0;
	node->game_over = 0;
	node->map = NULL;
	node->textures.collectible = NULL;
	node->textures.exit = NULL;
	node->textures.floor = NULL;
	node->textures.player = NULL;
	node->textures.player_down = NULL;
	node->textures.player_left = NULL;
	node->textures.player_right = NULL;
	node->textures.player_up = NULL;
	node->textures.wall = NULL;
	node->textures.current = NULL;
}

void	create_data(t_long_data **data)
{
	t_long_data	*node;

	node = malloc(sizeof(t_long_data));
	if (!node)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	fill_node(node);
	*data = node;
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
		error_msg();
	line = get_next_line(fd);
	while (line != NULL)
	{
		counter++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (counter);
}

int	get_map(t_long_data *data, char **av)
{
	int		lines;
	int		fd;
	int		i;

	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		error_msg();
	lines = count_lines(av);
	data->map = (char **)malloc(sizeof(char *) * (lines + 1));
	if (!data->map)
		error_msg();
	i = 0;
	while (i < lines)
	{
		data->map[i] = get_next_line(fd);
		i++;
	}
	data->map[i] = NULL;
	close(fd);
	return (0);
}

int	main(int ac, char **av)
{
	t_long_data	*data;

	if (ac != 2 || !(ft_strnstr(av[1], ".ber", ft_strlen(av[1]))))
		error_msg();
	create_data(&data);
	get_map(data, av);
	error_handling(data);
	map_drawing(data);
	return (0);
}
