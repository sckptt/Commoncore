#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stddef.h>
# include <stdio.h>
# include <limits.h>
# include "../minilibx-linux/mlx.h"

# define BUFFER_SIZE 1000

# define KEY_ESC 65307
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100

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
	void	*current;
}	t_textures;

typedef struct s_long_data
{
	int		map_height;
	int		map_width;
	int		player_position_x;
	int		player_position_y;
	int		player;
	int		exit;
	int		exit_x;
	int		exit_y;
	int		collectible;
	int		steps;
	int		game_over;
	char	**map;
	t_textures	textures;
}	t_long_data;

typedef struct s_mlx_data
{
	void	*mlx;
	void	*window;
}	t_mlx_data;

typedef struct s_hook_data
{
	t_long_data	*data;
	t_mlx_data	*mlx_data;
}	t_hook_data;

char	*get_next_line(int fd);
char	*gnl_strjoin(char const *s1, char const *s2);

int		get_map(t_long_data *data, char **av);
int		free_hook(t_hook_data *hook_data);

size_t	gnl_strlen(const char *str);
size_t	long_strlen(const char *str);


void	do_down(t_hook_data *hook_data, int x, int y);
void	do_left(t_hook_data *hook_data, int x, int y);
void	do_right(t_hook_data *hook_data, int x, int y);
void	do_up(t_hook_data *hook_data, int x, int y);
void	draw_picture(t_long_data *data, t_mlx_data *mlx_data, int x, int y);
void	draw_the_map(t_long_data *data, t_mlx_data *mlx_data);
void 	error_handling(t_long_data *data);
void	error_msg(void);
void	free_data(t_long_data *data);
void	free_mlx_and_data(t_long_data *data, t_mlx_data *mlx_data);
void	get_image(t_long_data *data, t_mlx_data *mlx_data, int width, int height);
void	hook_events(t_long_data *data, t_mlx_data *mlx_data);
void	map_analysis(t_long_data *data);
void	map_drawing(t_long_data *data);
void	redraw_map(t_hook_data *hook_data);
void	total_free(t_long_data *data, t_mlx_data *mlx_data);
void	valid_exit_collectible(t_long_data *data);

#endif