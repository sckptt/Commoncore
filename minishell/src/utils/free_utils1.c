/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arch <arch@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 15:59:39 by vitakinsfat       #+#    #+#             */
/*   Updated: 2024/12/04 21:20:23 by arch             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	close_exec_data_fd(t_list *list)
{
	int	i;

	i = -1;
	if (list->exec_data->fd)
	{
		while (++i < (list->size - 1))
		{
			if (list->exec_data->fd[i])
			{
				if (list->exec_data->fd[i][0] != -1)
					close(list->exec_data->fd[i][0]);
				if (list->exec_data->fd[i][1] != -1)
					close(list->exec_data->fd[i][1]);
				free(list->exec_data->fd[i]);
			}
		}
		free(list->exec_data->fd);
	}
}

void	free_exec_data(t_list *list)
{
	if (!list->exec_data)
		return ;
	if (list->exec_data->processes)
		free(list->exec_data->processes);
	close_exec_data_fd(list);
	free(list->exec_data);
}

void	free_cmd_argv(t_cmd *cmd)
{
	int	j;

	j = -1;
	if (!cmd)
		return ;
	if (cmd->argv)
	{
		while (cmd->argv[++j])
		{
			if (cmd->argv[j])
				free(cmd->argv[j]);
		}
		free(cmd->argv);
		cmd->argv = NULL;
	}
}

void	free_list_internals(t_list *list, int i)
{
	if (list->cmd[i].argv)
		free_cmd_argv(&list->cmd[i]);
	if (list->cmd[i].delim)
		free_char_array(list->cmd[i].delim);
	if (list->cmd[i].infile_name)
		free_char_array(list->cmd[i].infile_name);
	if (list->cmd[i].outfile_name)
		free_char_array(list->cmd[i].outfile_name);
	if (list->cmd[i].input_redir_type)
		free(list->cmd[i].input_redir_type);
	if (list->cmd[i].output_redir_type)
		free(list->cmd[i].output_redir_type);
	if (list->cmd[i].infile_fd != -1)
		close(list->cmd[i].infile_fd);
	if (list->cmd[i].outfile_fd != -1)
		close(list->cmd[i].outfile_fd);
	if (access("here_doc.txt", F_OK) != -1)
		unlink("here_doc.txt");
}

void	free_lists(t_list *list)
{
	int	i;

	if (!list)
		return ;
	free_exec_data(list);
	if (!list->cmd)
		return ;
	i = -1;
	while (++i < list->size)
		free_list_internals(list, i);
	if (list->cmd)
		free(list->cmd);
}
