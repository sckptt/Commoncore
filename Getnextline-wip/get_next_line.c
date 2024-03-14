/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitakinsfator <vitakinsfator@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 15:16:17 by vitakinsfat       #+#    #+#             */
/*   Updated: 2024/03/14 18:46:37 by vitakinsfat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_one_line(char *str)
{
	char	*one_line;
	size_t	len;

	len = 0;
	if (!str || str[0] == '\0')
		return (NULL);
	while (str[len] != '\n' && str[len] != '\0')
		len++;
	one_line = (char *)malloc(len + 1);
	if (!one_line)
		return (NULL);
	ft_strlcpy(one_line, str, len + 1);
	one_line[len] = '\0';
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
	if (buffer[i] != '\0')
		ft_strlcpy(new_buffer, buffer + i, ft_strlen(buffer + i) + 1);
	else
		new_buffer[0] = '\0';
	bytes_read = read(fd, new_buffer + ft_strlen(new_buffer),
			BUFFER_SIZE - ft_strlen(new_buffer));
	if (bytes_read <= 0)
	{
		free(new_buffer);
		return (NULL);
	}
	new_buffer[ft_strlen(new_buffer) + bytes_read] = '\0';
	free(buffer);
	return (new_buffer);
}

static char	*create_buffer(char *buffer, int fd)
{
	ssize_t		bytes_read;

	bytes_read = 0;
	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read <= 0)
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	buffer[bytes_read] = '\0';
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buffer)
	{
		buffer = create_buffer(buffer, fd);
		if (!buffer)
			return (NULL);
	}
	line = read_one_line(buffer);
	if (!line)
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	buffer = renew_buffer(buffer, fd);
	if (!buffer && !*line)
	{
		free(line);
		return (NULL);
	}
	return (line);
}

// int	main(void)
// {
// 	int		fd;
// 	char	*line;

// 	fd = open("burn_in_hell.txt", O_RDONLY);
// 	if (fd == -1)
// 	{
// 		printf("Error\n");
// 		return (1);
// 	}
// 	while ((line = get_next_line(fd)) != NULL)
// 	{
// 		if (*line == '\0')
// 			break;
// 		printf("%s\n", line);
// 		free(line);
// 	}
// 	close(fd);
// 	return (0);
// }
