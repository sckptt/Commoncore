/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkinsfat <vkinsfat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 17:22:18 by vkinsfat          #+#    #+#             */
/*   Updated: 2024/06/18 17:22:47 by vkinsfat         ###   ########.fr       */
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
