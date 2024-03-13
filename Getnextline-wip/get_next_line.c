/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitakinsfator <vitakinsfator@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 15:16:17 by vitakinsfat       #+#    #+#             */
/*   Updated: 2024/03/13 20:48:16 by vitakinsfat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static size_t	line_length(char *str)
{
	size_t	len;

	len = 0;
	while (str[len] != '\n')
		len++;
	return (len);
}

static char	*read_one_line(char *str)
{
	int		i;
	char	*one_line;

	i = 0;
	one_line = (char *)malloc(line_length(str) + 1);
	if (!one_line)
	{
		free(one_line);
		return (NULL);
	}
	while (str[i] != '\n' && str[i] != '\0')
	{
		one_line[i] = str[i];
		i++;
	}
	one_line[i] = '\0';
	return (one_line);
}

static char	*renew_buffer(char *buffer, int fd)
{
	char	*new_buffer;
	int		i;
	ssize_t	bytes_read;

	i = 0;
	while (buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	i++;
	new_buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!new_buffer)
		return (NULL);
	ft_strcpy(new_buffer, buffer + i);
	bytes_read = read(fd, new_buffer + ft_strlen(new_buffer),
			BUFFER_SIZE - (ft_strlen(new_buffer)));
	if (bytes_read <= 0)
	{
		free(new_buffer);
		return (NULL);
	}
	free(buffer);
	return (new_buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;
	ssize_t		bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buffer)
	{
		buffer = (char *)malloc(BUFFER_SIZE + 1);
		if (!buffer)
			return (NULL);
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
		{
			free(buffer);
			return (NULL);
		}
	}
	line = read_one_line(buffer);
	if (!line)
		return (NULL);
	buffer = renew_buffer(buffer, fd);
	if (!buffer)
		return (NULL);
	return (line);
}

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("burn_in_hell.txt", O_RDONLY);
	while (fd)
	{
		line = get_next_line(fd);
		printf("%s\n", line);
		free(line);
	}
	close(fd);
	return (0);
}
