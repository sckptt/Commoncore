/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkinsfat <vkinsfat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 20:31:26 by vkinsfat          #+#    #+#             */
/*   Updated: 2024/06/08 17:43:58 by vkinsfat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stddef.h>
# include <stdio.h>
# include <limits.h>
# include "../MLX42/include/MLX42/MLX42.h"

# define BUFFER_SIZE 42
# define WRONG_ARGS_MSG "Error\nNumber of arguments is not 2!\n"
# define NO_BER_MSG "Error\nFile is not .ber!\n"
# define EXTRA_SYMBOLS_MSG "Error\nExtra symbols in the map!\n"
# define NO_RECTANGLE_MSG "Error\nMap is not rectangular!\n"
# define NO_WALL_MSG "Error\nMap is not surrounded by walls!\n"
# define WRONG_EXIT_MSG "Error\nWrong number of exits!\n"
# define WRONG_PLAYER_MSG "Error\nWrong number of players!\n"
# define NO_COLLECTIBLES_MSG "Error\nNo collectibles in the map!\n"
# define NO_VALID_EXIT_OR_COLLECTIBLE_MSG "Error\nNo valid path in the map!\n"
# define ALLOCATION_ERROR "Error\nMemory allocation error!\n"
# define TEXTURE_ERROR "Error\nCan't load the texture!\n"
# define MLX_ERROR "Error\nCan't initialize MLX!\n"
# define COPY_ERROR "Error\nValid exit check, can't copy the map!\n"
# define FILE_ERROR "Error\nCan't open the file!\n"

typedef struct s_long_data
{
	int		map_height;
	int		map_width;
	int		player_x;
	int		player_y;
	int		num_player;
	int		num_exit;
	int		exit_x;
	int		exit_y;
	int		num_collectible;
	int		steps;
	int		game_over;
	char	**map;
	mlx_t	*mlx;
	void	*collectible;
	void	*exit;
	void	*floor;
	void	*player;
	void	*player_down;
	void	*player_left;
	void	*player_right;
	void	*player_up;
	void	*wall;
	void	*current;
}	t_long_data;

typedef struct s_textures
{
	void	*collectible;
	void	*exit;
	void	*floor;
	void	*player;
	void	*player_down;
	void	*player_left;
	void	*player_right;
	void	*player_up;
	void	*wall;
}	t_textures;

// GNL
char	*get_next_line(int fd);
char	*gnl_strjoin(char const *s1, char const *s2);
size_t	gnl_strlen(const char *str);

// Movements
void	do_down(t_long_data *data, int x, int y);
void	do_left(t_long_data *data, int x, int y);
void	do_right(t_long_data *data, int x, int y);
void	do_up(t_long_data *data, int x, int y);

// Map utils
int		count_lines(char **av);
int		get_map(t_long_data *data, char **av);
void	check_for_win(t_long_data *data, int x, int y);
void	draw_the_map(t_long_data *data, mlx_t *mlx);
void	game_start(t_long_data *data);
void	get_image(t_long_data *data, mlx_t *mlx, t_textures *textures);
void	hook_events(t_long_data *data);
void	key_press(mlx_key_data_t keydata, void *param);
void	redraw_map(t_long_data *data);

//Error check
int		check_filename(const char *arg);
size_t	long_strlen(const char *str);
void	error_handling(t_long_data *data);
void	map_analysis(t_long_data *data);
void	valid_exit_collectible(t_long_data *data);

//Free memory
void	free_data(t_long_data *data);
void	last_freeing(void *param);

#endif