/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_events.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkinsfat <vkinsfat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 01:03:00 by vitakinsfat       #+#    #+#             */
/*   Updated: 2024/06/04 20:55:02 by vkinsfat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../Libft/includes/libft.h"

void	redraw_map(t_hook_data *hook_data)
{
	int	x;
	int	y;

	x = hook_data->data->player_position_x;
	y = hook_data->data->player_position_y;
	mlx_clear_window(hook_data->mlx_data->mlx,
		hook_data->mlx_data->window);
	draw_the_map(hook_data->data, hook_data->mlx_data);
	if (hook_data->data->collectible == 0
		&& x == hook_data->data->exit_x
		&& y == hook_data->data->exit_y)
	{
		hook_data->data->game_over = 1;
		write(1, "You won!\n", 9);
		free_hook(hook_data);
		exit(0);
	}
}

int	key_press(int keycode, t_hook_data *hook_data)
{
	int	x;
	int	y;

	x = hook_data->data->player_position_x;
	y = hook_data->data->player_position_y;
	if (keycode == KEY_ESC)
	{
		free_hook(hook_data);
		exit(0);
	}
	if (keycode == KEY_W)
		do_up(hook_data, x - 1, y);
	if (keycode == KEY_A)
		do_left(hook_data, x, y - 1);
	if (keycode == KEY_S)
		do_down(hook_data, x + 1, y);
	if (keycode == KEY_D)
		do_right(hook_data, x, y + 1);
	return (0);
}

void	hook_events(t_long_data *data, t_mlx_data *mlx_data)
{
	t_hook_data	*hook_data;

	hook_data = malloc(sizeof(t_hook_data));
	if (!hook_data)
	{
		free_mlx_and_data(data, mlx_data);
		write(2, "Error\n", 6);
		exit(1);
	}
	hook_data->data = data;
	hook_data->mlx_data = mlx_data;
	mlx_hook(mlx_data->window, 2, (1L << 0), key_press, hook_data);
	mlx_hook(mlx_data->window, 17, (1L << 17), free_hook, hook_data);
	mlx_loop(mlx_data->mlx);
}
