/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_and_go_home.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkinsfat <vkinsfat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 23:33:44 by vitakinsfat       #+#    #+#             */
/*   Updated: 2024/06/06 20:22:06 by vkinsfat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../Libft/includes/libft.h"

static void	free_textures(t_long_data *data, mlx_t *mlx)
{
	if (data->collectible)
		mlx_delete_image(mlx, data->collectible);
	if (data->exit)
		mlx_delete_image(mlx, data->exit);
	if (data->floor)
		mlx_delete_image(mlx, data->floor);
	if (data->player)
		mlx_delete_image(mlx, data->player);
	if (data->player_down)
		mlx_delete_image(mlx, data->player_down);
	if (data->player_left)
		mlx_delete_image(mlx, data->player_left);
	if (data->player_right)
		mlx_delete_image(mlx, data->player_right);
	if (data->player_up)
		mlx_delete_image(mlx, data->player_up);
	if (data->wall)
		mlx_delete_image(mlx, data->wall);
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
	if (data->mlx)
	{
		free_textures(data, data->mlx);
		mlx_terminate(data->mlx);
	}
	free(data);
}

void	last_freeing(void *param)
{
	t_long_data	*data;

	data = (t_long_data *)param;
	free_data(data);
	exit(0);
}
