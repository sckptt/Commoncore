/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkinsfat <vkinsfat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 20:50:06 by vitakinsfat       #+#    #+#             */
/*   Updated: 2024/06/08 17:47:50 by vkinsfat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../Libft/includes/libft.h"

static void	fill_node(t_long_data *node)
{
	node->map_height = 0;
	node->map_width = 0;
	node->player_x = 0;
	node->player_y = 0;
	node->num_player = 0;
	node->num_exit = 0;
	node->exit_x = 0;
	node->exit_y = 0;
	node->num_collectible = 0;
	node->steps = 0;
	node->game_over = 0;
	node->map = NULL;
	node->mlx = NULL;
	node->collectible = NULL;
	node->exit = NULL;
	node->floor = NULL;
	node->player = NULL;
	node->player_down = NULL;
	node->player_left = NULL;
	node->player_right = NULL;
	node->player_up = NULL;
	node->wall = NULL;
	node->current = NULL;
}

static void	create_data(t_long_data **data)
{
	t_long_data	*node;

	node = malloc(sizeof(t_long_data));
	if (!node)
	{
		ft_putstr_fd(ALLOCATION_ERROR, 2);
		exit(1);
	}
	fill_node(node);
	*data = node;
}

int	main(int ac, char **av)
{
	t_long_data	*data;

	if (ac != 2)
	{
		ft_putstr_fd(WRONG_ARGS_MSG, 2);
		exit(1);
	}
	if (!check_filename(av[1]))
	{
		ft_putstr_fd(NO_BER_MSG, 2);
		exit(1);
	}
	create_data(&data);
	get_map(data, av);
	error_handling(data);
	game_start(data);
	mlx_key_hook(data->mlx, &key_press, data);
	mlx_close_hook(data->mlx, &last_freeing, data);
	mlx_loop(data->mlx);
	mlx_terminate(data->mlx);
	free_data(data);
	return (0);
}
