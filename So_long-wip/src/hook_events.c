/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_events.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkinsfat <vkinsfat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 01:03:00 by vitakinsfat       #+#    #+#             */
/*   Updated: 2024/06/08 17:44:50 by vkinsfat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../Libft/includes/libft.h"

void	check_for_win(t_long_data *data, int x, int y)
{
	if (data->num_collectible == 0
		&& x == data->exit_x && y == data->exit_y)
	{
		data->game_over = 1;
		write(1, "You won!\n", 9);
		free_data(data);
		exit(0);
	}
}

void	key_press(mlx_key_data_t keydata, void *param)
{
	int			x;
	int			y;
	t_long_data	*data;

	data = (t_long_data *)param;
	x = data->player_x;
	y = data->player_y;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		mlx_close_window(data->mlx);
		free_data(data);
		exit(0);
	}
	if ((keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		|| (keydata.key == MLX_KEY_UP && keydata.action == MLX_PRESS))
		do_up(data, x - 1, y);
	if ((keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		|| (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS))
		do_left(data, x, y - 1);
	if ((keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		|| (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_PRESS))
		do_down(data, x + 1, y);
	if ((keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		|| (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS))
		do_right(data, x, y + 1);
}
