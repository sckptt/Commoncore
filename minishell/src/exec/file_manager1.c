/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_manager1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkinsfat <vkinsfat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 18:51:46 by vkinsfat          #+#    #+#             */
/*   Updated: 2024/12/05 18:04:52 by vkinsfat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_folder_permission_ok(t_cmd *cmd, int i, char *folder_name)
{
	struct stat	path_stat;

	stat(folder_name, &path_stat);
	if (!S_ISDIR(path_stat.st_mode) && access(folder_name, F_OK) == 0)
	{
		free(folder_name);
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(cmd->outfile_name[i], 2);
		ft_putstr_fd(": Not a directory\n", 2);
		return (FAILURE);
	}
	if (ft_strlen(folder_name) == 1 && folder_name[0] == '/')
		return (free(folder_name), SUCCESS);
	if (access(folder_name, F_OK) == -1)
	{
		print_file_error(cmd->outfile_name[i]);
		return (free(folder_name), FAILURE);
	}
	if (access(folder_name, W_OK) == -1)
	{
		print_file_error(cmd->outfile_name[i]);
		return (free(folder_name), FAILURE);
	}
	free(folder_name);
	return (SUCCESS);
}

int	check_folder_permission(t_cmd *cmd, int i)
{
	char	*folder_name;

	if (ft_strrchr(cmd->outfile_name[i], '/') == NULL)
	{
		folder_name = ft_strdup(".");
		if (!folder_name)
			return (ft_putstr_fd(ALLOC_ERROR, 2), FAILURE);
	}
	else
	{
		folder_name = ft_strdup(cmd->outfile_name[i]);
		if (!folder_name)
			return (ft_putstr_fd(ALLOC_ERROR, 2), FAILURE);
		*ft_strrchr(folder_name, '/') = '\0';
	}
	if (is_folder_permission_ok(cmd, i, folder_name) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}

static int	manage_outfiles(t_cmd *cmd)
{
	int	i;

	i = -1;
	while (++i < cmd->num_of_outfiles)
	{
		if (check_folder_permission(cmd, i) == FAILURE)
			return (FAILURE);
		cmd->outfile_fd = open_files(cmd->outfile_name[i],
				cmd->output_redir_type[i], 0);
		if (access(cmd->outfile_name[i], W_OK) == -1)
			return (print_file_error(cmd->outfile_name[i]), FAILURE);
		if (i < cmd->num_of_outfiles - 1)
			close(cmd->outfile_fd);
	}
	return (SUCCESS);
}

static int	run_manage_files(t_cmd *cmd)
{
	if (cmd->num_of_infiles != 0)
	{
		if (manage_infiles(cmd) == FAILURE)
		{
			if (g_sig_received)
				g_sig_received = 0;
			return (FAILURE);
		}
	}
	if (cmd->num_of_outfiles != 0)
	{
		if (manage_outfiles(cmd) == FAILURE)
			return (FAILURE);
	}
	return (SUCCESS);
}

int	file_manager(t_list *list)
{
	int	i;

	i = -1;
	while (++i < list->size)
	{
		if (list->cmd[i].num_of_infiles != 0
			|| list->cmd[i].num_of_outfiles != 0)
		{
			if (run_manage_files(&list->cmd[i]) == FAILURE)
			{
				if (i == (list->size - 1))
				{
					list->exec_data->status = 1;
					return (FAILURE);
				}
			}
		}
	}
	return (SUCCESS);
}
