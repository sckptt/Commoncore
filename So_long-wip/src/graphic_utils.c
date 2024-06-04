/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkinsfat <vkinsfat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 14:32:37 by vkinsfat          #+#    #+#             */
/*   Updated: 2024/06/03 21:47:59 by vkinsfat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../Libft/includes/libft.h"

void	get_image(t_long_data *data,
		t_mlx_data *mlx_data, int width, int height)
{
	data->textures.collectible = mlx_xpm_file_to_image(mlx_data->mlx,
			"textures/collectible.xpm", &width, &height);
	data->textures.exit = mlx_xpm_file_to_image(mlx_data->mlx,
			"textures/exit.xpm", &width, &height);
	data->textures.floor = mlx_xpm_file_to_image(mlx_data->mlx,
			"textures/floor.xpm", &width, &height);
	data->textures.player = mlx_xpm_file_to_image(mlx_data->mlx,
			"textures/player.xpm", &width, &height);
	data->textures.player_down = mlx_xpm_file_to_image(mlx_data->mlx,
			"textures/player_down.xpm", &width, &height);
	data->textures.player_left = mlx_xpm_file_to_image(mlx_data->mlx,
			"textures/player_left.xpm", &width, &height);
	data->textures.player_right = mlx_xpm_file_to_image(mlx_data->mlx,
			"textures/player_right.xpm", &width, &height);
	data->textures.player_up = mlx_xpm_file_to_image(mlx_data->mlx,
			"textures/player_up.xpm", &width, &height);
	data->textures.wall = mlx_xpm_file_to_image(mlx_data->mlx,
			"textures/wall.xpm", &width, &height);
	data->textures.current = data->textures.player;
}

void	draw_picture(t_long_data *data, t_mlx_data *mlx_data, int x, int y)
{
	if (data->map[x][y] == '1')
		mlx_put_image_to_window(mlx_data->mlx, mlx_data->window,
			data->textures.wall, y * 100, x * 100);
	else if (data->map[x][y] == '0')
		mlx_put_image_to_window(mlx_data->mlx, mlx_data->window,
			data->textures.floor, y * 100, x * 100);
	else if (data->map[x][y] == 'P')
		mlx_put_image_to_window(mlx_data->mlx, mlx_data->window,
			data->textures.current, y * 100, x * 100);
	else if (data->map[x][y] == 'E')
		mlx_put_image_to_window(mlx_data->mlx, mlx_data->window,
			data->textures.exit, y * 100, x * 100);
	else if (data->map[x][y] == 'C')
		mlx_put_image_to_window(mlx_data->mlx, mlx_data->window,
			data->textures.collectible, y * 100, x * 100);
}
