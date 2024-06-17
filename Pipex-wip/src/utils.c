/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkinsfat <vkinsfat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 00:25:12 by vitakinsfat       #+#    #+#             */
/*   Updated: 2024/06/17 16:26:07 by vkinsfat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char	*find_paths(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (ft_strnstr(envp[i], "PATH=", 5))
			return (envp[i] + 5);
		i++;
	}
	return (NULL);
}

char	*make_command(t_pipe_data pipex, char **cmd)
{
	char	*temp;
	char	*command;
	int		i;

	i = 0;
	while (pipex.paths[i])
	{
		temp = ft_strjoin(pipex.paths[i], "/");
		command = ft_strjoin(temp, cmd[0]);
		free(temp);
		if (access(command, 0) == 0)
			return (command);
		free(command);
		i++;
	}
	return (NULL);
}

int	open_files(char **av, int is_in)
{
	int	res;

	res = 0;
	if (is_in == 1)
		res = open(av[1], O_RDONLY);
	else if (is_in == 0)
		res = open(av[4], O_RDWR | O_CREAT | O_TRUNC, 0644);
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
	if (pipex.infile >= 0)
		close(pipex.infile);
	if (pipex.outfile >= 0)
		close(pipex.outfile);
	if (pipex.fd[0] != -1)
	{
		printf("pipe[0] = %d\n", pipex.fd[0]);
		if (close(pipex.fd[0]) == -1)
			perror("Error closing fd[0]");
		pipex.fd[0] = -1;
	}
	if (pipex.fd[1] != -1)
	{
		printf("pipe[1] = %d\n", pipex.fd[1]);
		if (close(pipex.fd[1]) == -1)
			perror("Error closing fd[1]");
		pipex.fd[1] = -1;
	}
}
