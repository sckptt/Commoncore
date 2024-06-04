/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkinsfat <vkinsfat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 21:40:09 by vkinsfat          #+#    #+#             */
/*   Updated: 2024/06/04 21:29:29 by vkinsfat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../Libft/includes/libft.h"

void	do_up(t_hook_data *hook_data, int x, int y)
{
	int	*pos_x;
	int	*pos_y;
	int	*exit_x;
	int	*exit_y;

	pos_x = &hook_data->data->player_position_x;
	pos_y = &hook_data->data->player_position_y;
	exit_x = &hook_data->data->exit_x;
	exit_y = &hook_data->data->exit_y;
	if (hook_data->data->map[x][y] == '1')
		return ;
	if (hook_data->data->map[x][y] == 'C')
		hook_data->data->collectible--;
	hook_data->data->map[*pos_x][*pos_y] = '0';
	hook_data->data->map[x][y] = 'P';
	hook_data->data->player_position_x = x;
	hook_data->data->player_position_y = y;
	hook_data->data->steps++;
	ft_putnbr_fd(hook_data->data->steps, 1);
	write(1, "\n", 1);
	hook_data->data->textures.current = hook_data->data->textures.player_up;
	if (hook_data->data->map[*exit_x][*exit_y] == '0')
		hook_data->data->map[*exit_x][*exit_y] = 'E';
	redraw_map(hook_data);
}

void	do_down(t_hook_data *hook_data, int x, int y)
{
	int	*pos_x;
	int	*pos_y;
	int	*exit_x;
	int	*exit_y;

	pos_x = &hook_data->data->player_position_x;
	pos_y = &hook_data->data->player_position_y;
	exit_x = &hook_data->data->exit_x;
	exit_y = &hook_data->data->exit_y;
	if (hook_data->data->map[x][y] == '1')
		return ;
	if (hook_data->data->map[x][y] == 'C')
		hook_data->data->collectible--;
	hook_data->data->map[*pos_x][*pos_y] = '0';
	hook_data->data->map[x][y] = 'P';
	hook_data->data->player_position_x = x;
	hook_data->data->player_position_y = y;
	hook_data->data->steps++;
	ft_putnbr_fd(hook_data->data->steps, 1);
	write(1, "\n", 1);
	hook_data->data->textures.current = hook_data->data->textures.player_down;
	if (hook_data->data->map[*exit_x][*exit_y] == '0')
		hook_data->data->map[*exit_x][*exit_y] = 'E';
	redraw_map(hook_data);
}

void	do_left(t_hook_data *hook_data, int x, int y)
{
	int	*pos_x;
	int	*pos_y;
	int	*exit_x;
	int	*exit_y;

	pos_x = &hook_data->data->player_position_x;
	pos_y = &hook_data->data->player_position_y;
	exit_x = &hook_data->data->exit_x;
	exit_y = &hook_data->data->exit_y;
	if (hook_data->data->map[x][y] == '1')
		return ;
	if (hook_data->data->map[x][y] == 'C')
		hook_data->data->collectible--;
	hook_data->data->map[*pos_x][*pos_y] = '0';
	hook_data->data->map[x][y] = 'P';
	hook_data->data->player_position_x = x;
	hook_data->data->player_position_y = y;
	hook_data->data->steps++;
	ft_putnbr_fd(hook_data->data->steps, 1);
	write(1, "\n", 1);
	hook_data->data->textures.current = hook_data->data->textures.player_left;
	if (hook_data->data->map[*exit_x][*exit_y] == '0')
		hook_data->data->map[*exit_x][*exit_y] = 'E';
	redraw_map(hook_data);
}

void	do_right(t_hook_data *hook_data, int x, int y)
{
	int	*pos_x;
	int	*pos_y;
	int	*exit_x;
	int	*exit_y;

	pos_x = &hook_data->data->player_position_x;
	pos_y = &hook_data->data->player_position_y;
	exit_x = &hook_data->data->exit_x;
	exit_y = &hook_data->data->exit_y;
	if (hook_data->data->map[x][y] == '1')
		return ;
	if (hook_data->data->map[x][y] == 'C')
		hook_data->data->collectible--;
	hook_data->data->map[*pos_x][*pos_y] = '0';
	hook_data->data->map[x][y] = 'P';
	hook_data->data->player_position_x = x;
	hook_data->data->player_position_y = y;
	hook_data->data->steps++;
	ft_putnbr_fd(hook_data->data->steps, 1);
	write(1, "\n", 1);
	hook_data->data->textures.current = hook_data->data->textures.player_right;
	if (hook_data->data->map[*exit_x][*exit_y] == '0')
		hook_data->data->map[*exit_x][*exit_y] = 'E';
	redraw_map(hook_data);
}
