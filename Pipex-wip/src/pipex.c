/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitakinsfator <vitakinsfator@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 17:30:23 by vitakinsfat       #+#    #+#             */
/*   Updated: 2024/06/13 17:25:34 by vitakinsfat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	error_rising(t_pipe_data pipex)
{
	perror("Error");
	end_programm(pipex);
	exit(1);
}

void	first_child(t_pipe_data pipex, char **envp)
{
	char	*command;

	if (dup2(pipex.fd[1], 1) == -1)
		error_rising(pipex);
	close(pipex.fd[0]);
	if (dup2(pipex.infile, 0) == -1)
		error_rising(pipex);
	command = make_command(pipex, pipex.cmd1);
	if (!command)
		error_rising(pipex);
	if (execve(command, pipex.cmd1, envp) == -1)
		error_rising(pipex);
}

void	second_child(t_pipe_data pipex, char **envp)
{
	char	*command;

	if (dup2(pipex.fd[0], 0) == -1)
		error_rising(pipex);
	close(pipex.fd[1]);
	if (dup2(pipex.outfile, 1) == -1)
		error_rising(pipex);
	command = make_command(pipex, pipex.cmd2);
	if (!command)
		error_rising(pipex);
	if (execve(command, pipex.cmd2, envp) == -1)
		error_rising(pipex);
}

void	call_children(t_pipe_data pipex, char **envp)
{
	pipex.process1 = fork();
	if (pipex.process1 == -1)
		error_rising(pipex);
	if (pipex.process1 == 0)
		first_child(pipex, envp);
	waitpid(pipex.process1, NULL, 0);
	second_child(pipex, envp);
}

int	main(int ac, char **av, char **envp)
{
	t_pipe_data	pipex;
	char	*path;

	if (ac != 5)
	{
		ft_putstr_fd("Error: Wrong number of arguments\n", 2);
		exit(1);
	}
	pipex.infile = open_files(av, 1);
	pipex.outfile = open_files(av, 0);
	if (pipex.infile == -1)
		error_rising(pipex);
	if (pipex.outfile == -1)
		error_rising(pipex);
	if (pipe(pipex.fd) == -1)
		error_rising(pipex);
	path = find_paths(envp);
	pipex.paths = ft_split(path, ':');
	pipex.cmd1 = ft_split(av[2], ' ');
	pipex.cmd2 = ft_split(av[3], ' ');
	call_children(pipex, envp);
	end_programm(pipex);
}