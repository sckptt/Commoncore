/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkinsfat <vkinsfat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 17:30:23 by vitakinsfat       #+#    #+#             */
/*   Updated: 2024/06/25 19:05:06 by vkinsfat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	close_fds(t_pipe_data pipex, int child)
{
	if (child == 1)
	{
		close(pipex.fd[0]);
		close(pipex.fd[1]);
		close(pipex.infile);
	}
	if (child == 2)
	{
		close(pipex.fd[1]);
		close(pipex.fd[0]);
		close(pipex.outfile);
	}
}

void	first_child(t_pipe_data pipex, char **av, char **envp)
{
	char	*path;

	if (access(av[1], F_OK) == -1 || access(av[1], R_OK) == -1)
		error_rising(pipex);
	if (pipex.infile == -1)
		error_rising(pipex);
	if (dup2(pipex.fd[1], 1) == -1)
		error_rising(pipex);
	if (dup2(pipex.infile, 0) == -1)
		error_rising(pipex);
	close_fds(pipex, 1);
	path = make_command(pipex, pipex.cmd1);
	if (!path)
	{
		ft_putstr_fd("Error: command not found: ", 2);
		ft_putstr_fd(pipex.cmd1[0], 2);
		ft_putstr_fd("\n", 2);
		end_programm(pipex);
		exit(127);
	}
	if (execve(path, pipex.cmd1, envp) == -1)
	{
		free(path);
		error_rising(pipex);
	}
}

void	second_child(t_pipe_data pipex, char **av, char **envp)
{
	char	*path;

	if (access(av[4], W_OK) == -1)
		error_rising(pipex);
	if (pipex.outfile == -1)
		error_rising(pipex);
	if (dup2(pipex.fd[0], 0) == -1)
		error_rising(pipex);
	if (dup2(pipex.outfile, 1) == -1)
		error_rising(pipex);
	close_fds(pipex, 2);
	path = make_command(pipex, pipex.cmd2);
	if (!path)
	{
		ft_putstr_fd("Error: command not found: ", 2);
		ft_putstr_fd(pipex.cmd2[0], 2);
		ft_putstr_fd("\n", 2);
		end_programm(pipex);
		exit(127);
	}
	if (execve(path, pipex.cmd2, envp) == -1)
	{
		free(path);
		error_rising(pipex);
	}
}

void	call_children(t_pipe_data pipex, char **av, char **envp, int *status)
{
	pipex.process1 = fork();
	if (pipex.process1 == -1)
		error_rising(pipex);
	if (pipex.process1 == 0)
		first_child(pipex, av, envp);
	else
	{
		close(pipex.fd[1]);
		pipex.process2 = fork();
		if (pipex.process2 == -1)
			error_rising(pipex);
		if (pipex.process2 == 0)
			second_child(pipex, av, envp);
		else
		{
			close(pipex.fd[0]);
			waitpid(pipex.process1, status, 0);
			waitpid(pipex.process2, status, 0);
		}
	}
}

int	main(int ac, char **av, char **envp)
{
	t_pipe_data	pipex;
	char		*path;
	int			status;

	status = 0;
	check_args(ac, av);
	pipex.infile = open_files(av, 1);
	pipex.outfile = open_files(av, 0);
	if (pipe(pipex.fd) == -1)
		error_rising(pipex);
	path = find_paths(envp);
	pipex.paths = ft_split(path, ':');
	pipex.cmd1 = ft_split(av[2], ' ');
	pipex.cmd2 = ft_split(av[3], ' ');
	call_children(pipex, av, envp, &status);
	end_programm(pipex);
	if (WIFEXITED(status))
		exit(WEXITSTATUS(status));
	else
		exit(1);
}
