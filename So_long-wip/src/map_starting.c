/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_starting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkinsfat <vkinsfat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 20:24:13 by vkinsfat          #+#    #+#             */
/*   Updated: 2024/06/08 16:17:59 by vkinsfat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../Libft/includes/libft.h"

int	count_lines(char **av)
{
	int		fd;
	int		counter;
	char	*line;

	counter = 0;
	line = NULL;
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd(FILE_ERROR, 2);
		exit(1);
	}
	line = get_next_line(fd);
	while (line != NULL)
	{
		counter++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (counter);
}

static void	error(t_long_data *data)
{
	ft_putstr_fd(ALLOCATION_ERROR, 2);
	free_data(data);
	exit(1);
}

int	get_map(t_long_data *data, char **av)
{
	int		lines;
	int		fd;
	int		i;

	fd = open(av[1], O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd(FILE_ERROR, 2);
		free_data(data);
		exit(1);
	}
	lines = count_lines(av);
	data->map = (char **)malloc(sizeof(char *) * (lines + 1));
	if (!data->map)
		error(data);
	i = 0;
	while (i < lines)
	{
		data->map[i] = get_next_line(fd);
		i++;
	}
	data->map[i] = NULL;
	close(fd);
	return (0);
}
