/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitakinsfator <vitakinsfator@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 17:30:23 by vitakinsfat       #+#    #+#             */
/*   Updated: 2024/06/12 19:18:12 by vitakinsfat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	first_child(t_pipe_data pipex, char **envp)
{
	char	*command;

	dup2(pipex.fd[1], 1);
	close(pipex.fd[0]);
	dup2(pipex.infile, 0);
	command = make_command(pipex, pipex.cmd1);
	if (!command)
	{
		perror("Error");
		exit(1);
	}
	if (execve(command, pipex.cmd1, envp) == -1)
	{
		perror("Error");
		exit(1);
	}
}

void	second_child(t_pipe_data pipex, char **envp)
{
	char	*command;

	dup2(pipex.fd[0], 0);
	close(pipex.fd[1]);
	dup2(pipex.outfile, 1);
	command = make_command(pipex, pipex.cmd2);
	if (!command)
	{
		perror("Error");
		exit(1);
	}
	if (execve(command, pipex.cmd2, envp) == -1)
	{
		perror("Error");
		exit(1);
	}
}

int	main(int ac, char **av, char **envp)
{
	char		*path;
	t_pipe_data	pipex;

	if (ac != 5)
	{
		ft_putstr_fd("Error: Wrong number of arguments\n", 2);
		exit(1);
	}
	pipex.infile = open_files(av, 1);
	pipex.outfile = open_files(av, 0);
	if (pipe(pipex.fd) == -1)
	{
		perror("Error");
		exit(1);
	}
	path = find_paths(envp);
	pipex.paths = ft_split(path, ':');
	pipex.cmd1 = ft_split(av[2], ' ');
	pipex.cmd2 = ft_split(av[3], ' ');
	pipex.process1 = fork();
	if (pipex.process1 == 0)
		first_child(pipex, envp);
	waitpid(pipex.process1, NULL, 0);
	second_child(pipex, envp);
	close(pipex.infile);
	close(pipex.outfile);
}
