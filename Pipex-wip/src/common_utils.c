/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkinsfat <vkinsfat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 00:25:12 by vitakinsfat       #+#    #+#             */
/*   Updated: 2024/06/18 17:39:13 by vkinsfat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	error_rising(t_pipe_data pipex)
{
	perror("Error");
	end_programm(pipex);
	exit(1);
}

int	open_files(char **av, int is_in)
{
	int	res;

	res = 0;
	if (is_in == 1)
	{
		res = open(av[1], O_RDONLY);
		if (res == -1)
		{
			perror("Error");
			exit(1);
		}
	}
	else if (is_in == 0)
	{
		res = open(av[4], O_RDWR | O_CREAT | O_TRUNC, 0644);
		if (res == -1)
		{
			perror("Error");
			exit(1);
		}
	}
	return (res);
}

void	free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	end_programm(t_pipe_data pipex)
{
	if (pipex.cmd1)
		free_array(pipex.cmd1);
	if (pipex.cmd2)
		free_array(pipex.cmd2);
	if (pipex.paths)
		free_array(pipex.paths);
	if (pipex.infile != -1)
		close(pipex.infile);
	if (pipex.outfile != -1)
		close(pipex.outfile);
	if (pipex.fd[0] != -1)
		close(pipex.fd[0]);
	if (pipex.fd[1] != -1)
		close(pipex.fd[1]);
	exit(0);
}
