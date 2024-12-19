/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkinsfat <vkinsfat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 16:41:10 by vitakinsfat       #+#    #+#             */
/*   Updated: 2024/12/03 19:10:39 by vkinsfat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	execute_a_builtin(t_appdata *appdata, t_cmd *cmd)
{
	int	exit_status;

	exit_status = 0;
	if (ft_strcmp(cmd->argv[0], "cd") == 0)
		exit_status = ft_cd(cmd, appdata->env);
	else if (ft_strcmp(cmd->argv[0], "echo") == 0)
		exit_status = ft_echo(cmd);
	else if (ft_strcmp(cmd->argv[0], "env") == 0)
		exit_status = ft_env(appdata->env);
	else if (ft_strcmp(cmd->argv[0], "exit") == 0)
		exit_status = ft_exit(appdata, cmd);
	else if (ft_strcmp(cmd->argv[0], "export") == 0)
	{
		exit_status = ft_export(cmd, appdata->env);
		update_envp_array(appdata, appdata->env);
	}
	else if (ft_strcmp(cmd->argv[0], "pwd") == 0)
		exit_status = ft_pwd();
	else if (ft_strcmp(cmd->argv[0], "unset") == 0)
	{
		exit_status = ft_unset(cmd, appdata->env);
		update_envp_array(appdata, appdata->env);
	}
	return (exit_status);
}

static void	close_fd_builtin(int in, int out)
{
	if (in != -1)
	{
		dup2(in, 0);
		close(in);
	}
	if (out != -1)
	{
		dup2(out, 1);
		close(out);
	}
}

static void	redir_error(int in_backup, int out_backup, int is_stdin_error)
{
	if (is_stdin_error == 1)
	{
		if (in_backup != -1)
			close(in_backup);
	}
	if (is_stdin_error == 0)
	{
		if (in_backup != -1)
		{
			dup2(in_backup, 0);
			close(in_backup);
		}
		if (out_backup != -1)
			close(out_backup);
	}
}

static int	execute_single_builtin(t_appdata *appdata, t_list *list)
{
	int	exit_code;
	int	in_backup;
	int	out_backup;

	exit_code = 0;
	in_backup = -1;
	out_backup = -1;
	if (list->cmd[0].num_of_infiles > 0)
	{
		in_backup = dup(0);
		if (dup2(list->cmd[0].infile_fd, 0) == -1)
			return (redir_error(in_backup, out_backup, 1), FAILURE);
	}
	if (list->cmd[0].num_of_outfiles > 0)
	{
		out_backup = dup(1);
		if (dup2(list->cmd[0].outfile_fd, 1) == -1)
			return (redir_error(in_backup, out_backup, 0), FAILURE);
	}
	exit_code = execute_a_builtin(appdata, &list->cmd[0]);
	close_fd_builtin(in_backup, out_backup);
	return (exit_code);
}

int	execute_single(t_appdata *appdata, t_list *list)
{
	pid_t	pid;
	int		status;

	if (list->cmd->argc == 0)
		return (SUCCESS);
	if (list->cmd[0].is_builtin == FALSE)
	{
		pid = fork();
		if (pid == -1)
			return (perror("minishell: waitpid"), FAILURE);
		if (pid == 0)
			only_child(appdata, &list->cmd[0]);
		if (waitpid(pid, &status, 0) == -1)
			return (perror("minishell: waitpid"), FAILURE);
		if (WIFEXITED(status))
			list->exec_data->status = WEXITSTATUS(status);
		else if (WIFSIGNALED(status))
			list->exec_data->status = WTERMSIG(status) + SIGNAL_EXIT;
	}
	else
		list->exec_data->status = execute_single_builtin(appdata, list);
	return (SUCCESS);
}
