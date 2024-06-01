/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_events.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitakinsfator <vitakinsfator@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 01:03:00 by vitakinsfat       #+#    #+#             */
/*   Updated: 2024/05/31 20:35:47 by vitakinsfat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../Libft/includes/libft.h"

void you_won(t_hook_data **hook_data)
{
	if ((*(*hook_data)->data)->collectible == 0 
	&& (*(*hook_data)->data)->player_position_x == (*(*hook_data)->data)->exit_x
	&& (*(*hook_data)->data)->player_position_y == (*(*hook_data)->data)->exit_y)
	{
		(*(*hook_data)->data)->game_over = 1;
		write(1, "You won!\n", 9);
		free_hook(hook_data);
		exit(0);
	}
}

void do_move(t_hook_data **hook_data, int x, int y)
{
	if ((*(*hook_data)->data)->map[y][x] == '1')
		return ;
	if ((*(*hook_data)->data)->map[y][x] == 'C')
	{
		(*(*hook_data)->data)->collectible--;
		(*(*hook_data)->data)->map[y][x] = 'P';
	}
	//(*(*hook_data)->data->map[][] == '0';
	(*(*hook_data)->data)->player_position_x = x;
	(*(*hook_data)->data)->player_position_y = y;
	(*(*hook_data)->data)->steps++;
	you_won(hook_data);
}

void key_press(int keycode, t_hook_data **hook_data)
{
	if (keycode == KEY_ESC)
	{
		free_hook(hook_data);
		exit(0);
	}
	if (keycode == KEY_W)
		do_move(hook_data, (*(*hook_data)->data)->player_position_x, (*(*hook_data)->data)->player_position_y - 1);
	if (keycode == KEY_A)
		do_move(hook_data, (*(*hook_data)->data)->player_position_x - 1, (*(*hook_data)->data)->player_position_y);
	if (keycode == KEY_S)
		do_move(hook_data, (*(*hook_data)->data)->player_position_x, (*(*hook_data)->data)->player_position_y + 1);
	if (keycode == KEY_D)
		do_move(hook_data, (*(*hook_data)->data)->player_position_x + 1, (*(*hook_data)->data)->player_position_y);
}

void hook_events(t_long_data **data, t_mlx_data **mlx_data)
{
	t_hook_data	*hook_data;
	
	hook_data = malloc(sizeof(t_hook_data));
	if (!hook_data)
	{
		write(2, "Error\n", 6);
		free_mlx_and_data(data, mlx_data);
		exit(1);
	}
	hook_data->data = data;
	hook_data->mlx_data = mlx_data;
	mlx_hook((*mlx_data)->window, 2, 0, key_press, hook_data);
	mlx_hook((*mlx_data)->window, 17, 0, free_hook, hook_data);
}
