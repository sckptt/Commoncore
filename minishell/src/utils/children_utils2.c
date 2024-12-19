/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   children_utils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkinsfat <vkinsfat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 17:30:44 by akulikov          #+#    #+#             */
/*   Updated: 2024/12/05 18:16:26 by vkinsfat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_child_error_message(char *cmd_name)
{
	ft_putstr_fd(cmd_name, 2);
	ft_putstr_fd(": command not found\n", 2);
	exit(127);
}

void	exec_error(char *argument)
{
	int			exit_code;
	struct stat	path_stat;

	exit_code = 1;
	stat(argument, &path_stat);
	if (S_ISDIR(path_stat.st_mode))
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(argument, 2);
		ft_putstr_fd(": Is a directory\n", 2);
		exit_code = COMMAND_NOT_EXECUTABLE;
	}
	else
	{
		if (errno == EACCES)
			exit_code = COMMAND_NOT_EXECUTABLE;
		else if (errno == ENOENT)
			exit_code = COMMAND_NOT_FOUND;
		else if (errno == ENOMEM)
			exit_code = FAILURE;
		ft_putstr_fd("minishell: ", 2);
		perror(argument);
	}
	exit(exit_code);
}

void	pipe_redirection(t_exec_data *exec_data, t_cmd *cmd, int i)
{
	if (cmd->num_of_infiles == 0)
	{
		if (dup2(exec_data->fd[i - 1][0], 0) == -1)
			exit(1);
	}
	if (cmd->num_of_outfiles == 0)
	{
		if (dup2(exec_data->fd[i][1], 1) == -1)
			exit(1);
	}
}
