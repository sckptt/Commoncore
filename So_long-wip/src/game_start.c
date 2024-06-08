/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_start.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkinsfat <vkinsfat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 17:20:55 by vkinsfat          #+#    #+#             */
/*   Updated: 2024/06/08 16:12:18 by vkinsfat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../Libft/includes/libft.h"

static void	get_textures(t_long_data *data, mlx_t *mlx)
{
	t_textures	*textures;

	textures = malloc(sizeof(t_textures));
	if (!textures)
	{
		ft_putstr_fd(ALLOCATION_ERROR, 2);
		free_data(data);
		mlx_terminate(data->mlx);
		exit(1);
	}
	textures->collectible = mlx_load_png("textures/collectible.png");
	textures->exit = mlx_load_png("textures/exit.png");
	textures->floor = mlx_load_png("textures/floor.png");
	textures->player = mlx_load_png("textures/player.png");
	textures->player_down = mlx_load_png("textures/player_down.png");
	textures->player_left = mlx_load_png("textures/player_left.png");
	textures->player_right = mlx_load_png("textures/player_right.png");
	textures->player_up = mlx_load_png("textures/player_up.png");
	textures->wall = mlx_load_png("textures/wall.png");
	get_image(data, mlx, textures);
}

void	get_image(t_long_data *data, mlx_t *mlx, t_textures *textures)
{
	data->collectible = mlx_texture_to_image(mlx, textures->collectible);
	data->exit = mlx_texture_to_image(mlx, textures->exit);
	data->floor = mlx_texture_to_image(mlx, textures->floor);
	data->player = mlx_texture_to_image(mlx, textures->player);
	data->player_down = mlx_texture_to_image(mlx, textures->player_down);
	data->player_left = mlx_texture_to_image(mlx, textures->player_left);
	data->player_right = mlx_texture_to_image(mlx, textures->player_right);
	data->player_up = mlx_texture_to_image(mlx, textures->player_up);
	data->wall = mlx_texture_to_image(mlx, textures->wall);
	data->current = data->player;
	mlx_delete_texture(textures->collectible);
	mlx_delete_texture(textures->exit);
	mlx_delete_texture(textures->floor);
	mlx_delete_texture(textures->player);
	mlx_delete_texture(textures->player_down);
	mlx_delete_texture(textures->player_left);
	mlx_delete_texture(textures->player_right);
	mlx_delete_texture(textures->player_up);
	mlx_delete_texture(textures->wall);
	free(textures);
}

static void	get_in_struct(t_long_data *data, mlx_t *mlx)
{
	get_textures(data, mlx);
	if (!data->collectible || !data->exit
		|| !data->floor || !data->player
		|| !data->wall || !data->player_down
		|| !data->player_left || !data->player_right
		|| !data->player_up)
	{
		ft_putstr_fd(TEXTURE_ERROR, 2);
		free_data(data);
		mlx_terminate(data->mlx);
		exit(1);
	}
}

void	draw_the_map(t_long_data *data, mlx_t *mlx)
{
	int	x;
	int	y;

	x = 0;
	while (data->map[x])
	{
		y = 0;
		while (data->map[x][y])
		{
			if (data->map[x][y] == '1')
				mlx_image_to_window(mlx, data->wall, y * 100, x * 100);
			else if (data->map[x][y] == '0')
				mlx_image_to_window(mlx, data->floor, y * 100, x * 100);
			else if (data->map[x][y] == 'P')
				mlx_image_to_window(mlx, data->current, y * 100, x * 100);
			else if (data->map[x][y] == 'E')
				mlx_image_to_window(mlx, data->exit, y * 100, x * 100);
			else if (data->map[x][y] == 'C')
				mlx_image_to_window(mlx, data->collectible,
					y * 100, x * 100);
			y++;
		}
		x++;
	}
}

void	game_start(t_long_data *data)
{
	data->mlx = mlx_init(data->map_width * 100, data->map_height * 100,
			"so_long", false);
	if (!data->mlx)
	{
		ft_putstr_fd(MLX_ERROR, 2);
		free_data(data);
		exit(1);
	}
	get_in_struct(data, data->mlx);
	draw_the_map(data, data->mlx);
}
