/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   children_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akulikov <akulikov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 16:48:47 by vitakinsfat       #+#    #+#             */
/*   Updated: 2024/12/03 17:31:10 by akulikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**find_paths(char **envp)
{
	int		i;
	char	*path;
	char	**paths;

	i = 0;
	while (envp[i])
	{
		if (ft_strnstr(envp[i], "PATH=", 5))
		{
			path = ft_strdup(envp[i] + 5);
			if (!path)
				return (ft_putstr_fd(ALLOC_ERROR, 2), NULL);
			paths = ft_split(path, ':');
			if (!path)
				return (free(path), ft_putstr_fd(ALLOC_ERROR, 2), NULL);
			return (free(path), paths);
		}
		i++;
	}
	return (NULL);
}

char	*create_path_string(t_cmd *cmd, char *path)
{
	char	*cmd_with_slash;
	char	*current_path;

	cmd_with_slash = ft_strjoin("/", cmd->argv[0]);
	current_path = ft_strjoin(path, cmd_with_slash);
	free(cmd_with_slash);
	return (current_path);
}

char	*make_path(t_cmd *cmd, char **envp)
{
	int		i;
	char	**paths;
	char	*current_path;

	if (cmd->argv[0][0] == '/')
	{
		current_path = ft_strdup(cmd->argv[0]);
		return (current_path);
	}
	i = 0;
	paths = find_paths(envp);
	if (!paths)
		return (NULL);
	while (paths[i])
	{
		current_path = create_path_string(cmd, paths[i]);
		if (access(current_path, F_OK) == 0)
			return (free_char_array(paths), current_path);
		free(current_path);
		i++;
	}
	free_char_array(paths);
	return (NULL);
}

int	io_redirection(t_cmd *cmd)
{
	if (cmd->num_of_infiles != 0)
	{
		if (dup2(cmd->infile_fd, 0) == -1)
			return (FAILURE);
	}
	if (cmd->num_of_outfiles != 0)
	{
		if (dup2(cmd->outfile_fd, 1) == -1)
			return (FAILURE);
	}
	return (SUCCESS);
}

void	close_fds(t_cmd *cmd, t_exec_data *exec_data, int current_pipe)
{
	int	i;
	int	num_of_cmd;

	i = -1;
	num_of_cmd = *exec_data->num_of_cmd;
	while (++i < num_of_cmd - 1)
	{
		if (i != current_pipe - 1)
			close(exec_data->fd[i][0]);
		if (i != current_pipe)
			close(exec_data->fd[i][1]);
	}
	if (current_pipe != 0 && cmd->infile_fd != -1)
		close(cmd->infile_fd);
	if (current_pipe != (num_of_cmd - 1) && cmd->outfile_fd != -1)
		close(cmd->outfile_fd);
}
