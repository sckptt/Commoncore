/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_and_go_home.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkinsfat <vkinsfat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 23:33:44 by vitakinsfat       #+#    #+#             */
/*   Updated: 2024/06/04 21:35:10 by vkinsfat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../Libft/includes/libft.h"

void	free_mlx_data(t_mlx_data *mlx_data)
{
	if (mlx_data->window)
		mlx_destroy_window(mlx_data->mlx, mlx_data->window);
	if (mlx_data->mlx)
		mlx_destroy_display(mlx_data->mlx);
	free(mlx_data);
}

void	free_textures(t_long_data *data, t_mlx_data *mlx_data)
{
	if (data->textures.collectible)
		mlx_destroy_image(mlx_data->mlx, data->textures.collectible);
	if (data->textures.exit)
		mlx_destroy_image(mlx_data->mlx, data->textures.exit);
	if (data->textures.floor)
		mlx_destroy_image(mlx_data->mlx, data->textures.floor);
	if (data->textures.player)
		mlx_destroy_image(mlx_data->mlx, data->textures.player);
	if (data->textures.player_down)
		mlx_destroy_image(mlx_data->mlx, data->textures.player_down);
	if (data->textures.player_left)
		mlx_destroy_image(mlx_data->mlx, data->textures.player_left);
	if (data->textures.player_right)
		mlx_destroy_image(mlx_data->mlx, data->textures.player_right);
	if (data->textures.player_up)
		mlx_destroy_image(mlx_data->mlx, data->textures.player_up);
	if (data->textures.wall)
		mlx_destroy_image(mlx_data->mlx, data->textures.wall);
}

void	free_data(t_long_data *data)
{
	int	i;

	i = 0;
	if (data->map)
	{
		while (data->map[i])
		{
			free(data->map[i]);
			i++;
		}
		free(data->map);
	}
	free(data);
}

void	free_mlx_and_data(t_long_data *data, t_mlx_data *mlx_data)
{
	free_textures(data, mlx_data);
	free_mlx_data(mlx_data);
	free_data(data);
}

int	free_hook(t_hook_data *hook_data)
{
	free_mlx_and_data(hook_data->data, hook_data->mlx_data);
	free(hook_data);
	return (0);
}
