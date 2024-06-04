/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_start.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkinsfat <vkinsfat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 17:20:55 by vkinsfat          #+#    #+#             */
/*   Updated: 2024/06/04 22:05:49 by vkinsfat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../Libft/includes/libft.h"

static void	error_exit(t_long_data *data)
{
	write(2, "Error\n", 6);
	free_data(data);
	exit(1);
}

static t_mlx_data	*mlx_data_init(t_long_data *data)
{
	t_mlx_data	*node;

	node = malloc(sizeof(t_mlx_data));
	if (!node)
		error_exit(data);
	node->mlx = mlx_init();
	if (!node->mlx)
	{
		free(node);
		error_exit(data);
	}
	node->window = mlx_new_window(node->mlx,
			data->map_width * 100, data->map_height * 100, "so_long");
	if (!node->window)
	{
		mlx_destroy_display(node->mlx);
		free(node);
		error_exit(data);
	}
	return (node);
}

static void	get_textures(t_long_data *data, t_mlx_data *mlx_data)
{
	int	width;
	int	height;

	width = 0;
	height = 0;
	get_image(data, mlx_data, width, height);
	if (!data->textures.collectible || !data->textures.exit
		|| !data->textures.floor || !data->textures.player
		|| !data->textures.wall || !data->textures.player_down
		|| !data->textures.player_left || !data->textures.player_right
		|| !data->textures.player_up)
	{
		write(2, "Error\n", 6);
		free_mlx_and_data(data, mlx_data);
		exit(1);
	}
}

void	draw_the_map(t_long_data *data, t_mlx_data *mlx_data)
{
	int	x;
	int	y;

	x = 0;
	while (data->map[x])
	{
		y = 0;
		while (data->map[x][y])
		{
			draw_picture(data, mlx_data, x, y);
			y++;
		}
		x++;
	}
}

void	map_drawing(t_long_data *data)
{
	t_mlx_data	*mlx_data;

	mlx_data = mlx_data_init(data);
	get_textures(data, mlx_data);
	draw_the_map(data, mlx_data);
	hook_events(data, mlx_data);
}
