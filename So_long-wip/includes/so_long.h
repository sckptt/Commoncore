#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stddef.h>
# include <stdio.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

typedef struct s_long_data
{
	int				map_height;
	int				map_width;
	int				player_position_x;
	int				player_position_y;
	int				player;
	int				exit;
	int				collectible;
	int				steps;
	char			**map;
}	t_long_data;

char	*get_next_line(int fd);
char	*gnl_strjoin(char const *s1, char const *s2);

int	get_map(t_long_data **data, char **av);

size_t	gnl_strlen(const char *str);
size_t	long_strlen(const char *str);

void error_handling(t_long_data **data);
void free_data(t_long_data **data);
void map_analysis(t_long_data **data);

#endif