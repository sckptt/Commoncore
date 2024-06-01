/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_start.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitakinsfator <vitakinsfator@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 17:20:55 by vkinsfat          #+#    #+#             */
/*   Updated: 2024/05/31 01:03:18 by vitakinsfat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../Libft/includes/libft.h"

static void	mlx_data_init(t_long_data **data, t_mlx_data **mlx_data)
{
	t_mlx_data	*node;

	node = malloc(sizeof(t_mlx_data));
	if (!node)
	{
		write(2, "Error\n", 6);
		free_data(data);
		exit(1);
	}
	node->mlx = mlx_init();
	node->window = mlx_new_window(node->mlx, (*data)->map_width * 100, (*data)->map_height * 100, "so_long");
	if (!node->mlx || !node->window)
	{
		write(2, "Error\n", 6);
		if (node->mlx)
			mlx_destroy_display(node->mlx);
		free(node);
		free_data(data);
		exit(1);
	}
	*mlx_data = node;
}

static void	get_textures(t_long_data **data, t_mlx_data **mlx_data)
{
	int	width;
	int	height;

	(*data)->textures.collectible = mlx_xpm_file_to_image((*mlx_data)->mlx, "textures/collectible.xpm", &width, &height);
	(*data)->textures.exit = mlx_xpm_file_to_image((*mlx_data)->mlx, "textures/exit.xpm", &width, &height);
	(*data)->textures.floor = mlx_xpm_file_to_image((*mlx_data)->mlx, "textures/floor.xpm", &width, &height);
	(*data)->textures.player = mlx_xpm_file_to_image((*mlx_data)->mlx, "textures/player.xpm", &width, &height);
	(*data)->textures.player_down = mlx_xpm_file_to_image((*mlx_data)->mlx, "textures/player_down.xpm", &width, &height);
	(*data)->textures.player_left = mlx_xpm_file_to_image((*mlx_data)->mlx, "textures/player_left.xpm", &width, &height);
	(*data)->textures.player_right = mlx_xpm_file_to_image((*mlx_data)->mlx, "textures/player_right.xpm", &width, &height);
	(*data)->textures.player_up = mlx_xpm_file_to_image((*mlx_data)->mlx, "textures/player_up.xpm", &width, &height);
	(*data)->textures.wall = mlx_xpm_file_to_image((*mlx_data)->mlx, "textures/wall.xpm", &width, &height);
	if (!(*data)->textures.collectible || !(*data)->textures.exit
	|| !(*data)->textures.floor || !(*data)->textures.player
	|| !(*data)->textures.wall || !(*data)->textures.player_down 
	|| !(*data)->textures.player_left || !(*data)->textures.player_right 
	|| !(*data)->textures.player_up)
	{
		write(2, "Error\n", 6);
		free_data(data);
		exit(1);
	}
}

static void	draw_the_map(t_long_data **data, t_mlx_data **mlx_data)
{
	int x;
	int y;

	x = 0;
	while ((*data)->map[x])
	{
		y = 0;
		while ((*data)->map[x][y])
		{
			if ((*data)->map[x][y] == '1')
				mlx_put_image_to_window((*mlx_data)->mlx, (*mlx_data)->window, (*data)->textures.wall, x * 100, y * 100);
			else if ((*data)->map[x][y] == '0')
				mlx_put_image_to_window((*mlx_data)->mlx, (*mlx_data)->window, (*data)->textures.floor, x * 100, y * 100);
			else if ((*data)->map[x][y] == 'P')
				mlx_put_image_to_window((*mlx_data)->mlx, (*mlx_data)->window, (*data)->textures.player, x * 100, y * 100);
			else if ((*data)->map[x][y] == 'E')
				mlx_put_image_to_window((*mlx_data)->mlx, (*mlx_data)->window, (*data)->textures.exit, x * 100, y * 100);
			else if ((*data)->map[x][y] == 'C')
				mlx_put_image_to_window((*mlx_data)->mlx, (*mlx_data)->window, (*data)->textures.collectible, x * 100, y * 100);
			y++;
		}
		x++;
	}
}

void	map_drawing(t_long_data **data)
{
	t_mlx_data	*mlx_data;

	mlx_data_init(data, &mlx_data);
	get_textures(data, &mlx_data);
	draw_the_map(data, &mlx_data);
	hook_events(data, &mlx_data);
	mlx_loop(mlx_data->mlx);
}
