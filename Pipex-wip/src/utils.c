/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitakinsfator <vitakinsfator@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 00:25:12 by vitakinsfat       #+#    #+#             */
/*   Updated: 2024/06/12 19:13:35 by vitakinsfat      ###   ########.fr       */
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
	char *temp;
	char *command;
	int i;

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
	int res;

	res = 0;
	if (is_in == 1)
	{
		res = open(av[1], O_RDONLY);
		if (res < 0)
		{
			perror("Error");
			exit(1);
		}
	}
	else if (is_in == 0)
	{
		res = open(av[4], O_RDWR | O_CREAT | O_TRUNC, 0644);
		if (res < 0)
		{
			perror("Error");
			exit(1);
		}
	}
	return (res);
}

// char	**parse_command(char *cmd)
// {
// 	char	**cmd_split;

// 	cmd_split = ft_split(cmd, ' ');
// 	if (access(cmd_split[0], F_OK) == 0)
// 		return (cmd_split);
// 	else if (access(cmd_split[0], F_OK) == -1)
// 	{
// 		cmd_split[0] = ft_strjoin("/", cmd_split[0]);
// 		return (cmd_split);
// 	}
// 	return (NULL);
// }
