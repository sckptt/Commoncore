/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   children.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkinsfat <vkinsfat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 16:01:16 by vitakinsfat       #+#    #+#             */
/*   Updated: 2024/12/05 18:13:41 by vkinsfat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	first_child(t_appdata *appdata, t_exec_data *exec_data, t_cmd *cmd)
{
	char	*path;
	int		status;

	status = 0;
	if (cmd->argc == 0)
		exit (0);
	if (io_redirection(cmd) == FAILURE)
		exit (1);
	if (cmd->num_of_outfiles == 0)
	{
		if (dup2(exec_data->fd[0][1], 1) == -1)
			exit(1);
	}
	close_fds(cmd, exec_data, 0);
	if (cmd->is_builtin == TRUE)
	{
		status = execute_a_builtin(appdata, cmd);
		exit(status);
	}
	path = make_path(cmd, appdata->envp);
	if (!path)
		print_child_error_message(cmd->argv[0]);
	if (execve(path, cmd->argv, appdata->envp) == -1)
		exec_error(cmd->argv[0]);
}

void	last_child(t_appdata *appdata,
	t_exec_data *exec_data, t_cmd *cmd, int i)
{
	char	*path;
	int		status;

	status = 0;
	if (cmd->argc == 0)
		exit (0);
	if (io_redirection(cmd) == FAILURE)
		exit (1);
	if (cmd->num_of_infiles == 0)
	{
		if (dup2(exec_data->fd[i - 1][0], 0) == -1)
			exit(1);
	}
	close_fds(cmd, exec_data, i);
	if (cmd->is_builtin == TRUE)
	{
		status = execute_a_builtin(appdata, cmd);
		exit(status);
	}
	path = make_path(cmd, appdata->envp);
	if (!path)
		print_child_error_message(cmd->argv[0]);
	if (execve(path, cmd->argv, appdata->envp) == -1)
		exec_error(cmd->argv[0]);
}

void	mid_child(t_appdata *appdata, t_exec_data *exec_data, t_cmd *cmd, int i)
{
	char	*path;
	int		status;

	status = 0;
	if (cmd->argc == 0)
		exit (0);
	pipe_redirection(exec_data, cmd, i);
	close_fds(cmd, exec_data, i);
	if (cmd->is_builtin == TRUE)
	{
		status = execute_a_builtin(appdata, cmd);
		exit(status);
	}
	path = make_path(cmd, appdata->envp);
	if (!path)
		print_child_error_message(cmd->argv[0]);
	if (execve(path, cmd->argv, appdata->envp) == -1)
		exec_error(cmd->argv[0]);
}

void	only_child(t_appdata *appdata, t_cmd *cmd)
{
	char	*path;

	if (cmd->argc == 0)
		exit (0);
	if (cmd->num_of_infiles != 0)
	{
		if (dup2(cmd->infile_fd, 0) == -1)
			exit(1);
		close(cmd->infile_fd);
	}
	if (cmd->num_of_outfiles != 0)
	{
		if (dup2(cmd->outfile_fd, 1) == -1)
			exit(1);
		close(cmd->outfile_fd);
	}
	path = make_path(cmd, appdata->envp);
	if (!path)
		print_child_error_message(cmd->argv[0]);
	if (execve(path, cmd->argv, appdata->envp) == -1)
	{
		free(path);
		exec_error(cmd->argv[0]);
	}
}
