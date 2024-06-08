/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkinsfat <vkinsfat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 21:40:09 by vkinsfat          #+#    #+#             */
/*   Updated: 2024/06/08 17:52:20 by vkinsfat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../Libft/includes/libft.h"

void	do_up(t_long_data *data, int x, int y)
{
	if (data->map[x][y] == '1')
		return ;
	if (data->map[x][y] == 'C')
		data->num_collectible--;
	data->map[data->player_x][data->player_y] = '0';
	mlx_image_to_window(data->mlx, data->floor,
		data->player_y * 100, data->player_x * 100);
	data->map[x][y] = 'P';
	data->current = data->player_up;
	mlx_image_to_window(data->mlx, data->current, y * 100, x * 100);
	data->player_x = x;
	data->player_y = y;
	data->steps++;
	ft_putnbr_fd(data->steps, 1);
	write(1, "\n", 1);
	if (data->map[data->exit_x][data->exit_y] == '0')
	{
		data->map[data->exit_x][data->exit_y] = 'E';
		mlx_image_to_window(data->mlx, data->exit, data->exit_y * 100,
			data->exit_x * 100);
	}
	check_for_win(data, data->player_x, data->player_y);
}

void	do_down(t_long_data *data, int x, int y)
{
	if (data->map[x][y] == '1')
		return ;
	if (data->map[x][y] == 'C')
		data->num_collectible--;
	data->map[data->player_x][data->player_y] = '0';
	mlx_image_to_window(data->mlx, data->floor,
		data->player_y * 100, data->player_x * 100);
	data->map[x][y] = 'P';
	data->current = data->player_down;
	mlx_image_to_window(data->mlx, data->current, y * 100, x * 100);
	data->player_x = x;
	data->player_y = y;
	data->steps++;
	ft_putnbr_fd(data->steps, 1);
	write(1, "\n", 1);
	if (data->map[data->exit_x][data->exit_y] == '0')
	{
		data->map[data->exit_x][data->exit_y] = 'E';
		mlx_image_to_window(data->mlx, data->exit, data->exit_y * 100,
			data->exit_x * 100);
	}
	check_for_win(data, data->player_x, data->player_y);
}

void	do_left(t_long_data *data, int x, int y)
{
	if (data->map[x][y] == '1')
		return ;
	if (data->map[x][y] == 'C')
		data->num_collectible--;
	data->map[data->player_x][data->player_y] = '0';
	mlx_image_to_window(data->mlx, data->floor,
		data->player_y * 100, data->player_x * 100);
	data->map[x][y] = 'P';
	data->current = data->player_left;
	mlx_image_to_window(data->mlx, data->current, y * 100, x * 100);
	data->player_x = x;
	data->player_y = y;
	data->steps++;
	ft_putnbr_fd(data->steps, 1);
	write(1, "\n", 1);
	if (data->map[data->exit_x][data->exit_y] == '0')
	{
		data->map[data->exit_x][data->exit_y] = 'E';
		mlx_image_to_window(data->mlx, data->exit, data->exit_y * 100,
			data->exit_x * 100);
	}
	check_for_win(data, data->player_x, data->player_y);
}

void	do_right(t_long_data *data, int x, int y)
{
	if (data->map[x][y] == '1')
		return ;
	if (data->map[x][y] == 'C')
		data->num_collectible--;
	data->map[data->player_x][data->player_y] = '0';
	mlx_image_to_window(data->mlx, data->floor,
		data->player_y * 100, data->player_x * 100);
	data->map[x][y] = 'P';
	data->current = data->player_right;
	mlx_image_to_window(data->mlx, data->current, y * 100, x * 100);
	data->player_x = x;
	data->player_y = y;
	data->steps++;
	ft_putnbr_fd(data->steps, 1);
	write(1, "\n", 1);
	if (data->map[data->exit_x][data->exit_y] == '0')
	{
		data->map[data->exit_x][data->exit_y] = 'E';
		mlx_image_to_window(data->mlx, data->exit, data->exit_y * 100,
			data->exit_x * 100);
	}
	check_for_win(data, data->player_x, data->player_y);
}
