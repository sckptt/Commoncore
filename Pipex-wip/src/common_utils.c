/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkinsfat <vkinsfat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 00:25:12 by vitakinsfat       #+#    #+#             */
/*   Updated: 2024/06/25 19:05:21 by vkinsfat         ###   ########.fr       */
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
	if (pipex.infile != -1)
		close(pipex.infile);
	if (pipex.outfile != -1)
		close(pipex.outfile);
	if (pipex.fd[0] != -1)
		close(pipex.fd[0]);
	if (pipex.fd[1] != -1)
		close(pipex.fd[1]);
}

void	check_args(int ac, char **av)
{
	if (ac != 5)
	{
		ft_putstr_fd("Error: wrong number of arguments\n", 2);
		exit(1);
	}
	if (av[2][0] == '\0' || av[3][0] == '\0')
	{
		if (av[2][0] == '\0')
		{
			ft_putstr_fd("Error: command not found: ", 2);
			ft_putstr_fd(av[2], 2);
			ft_putstr_fd("\n", 2);
		}
		if (av[3][0] == '\0')
		{
			ft_putstr_fd("Error: command not found: ", 2);
			ft_putstr_fd(av[3], 2);
			ft_putstr_fd("\n", 2);
		}
		exit(127);
	}
}
