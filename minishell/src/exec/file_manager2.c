/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_manager2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkinsfat <vkinsfat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 18:51:15 by vkinsfat          #+#    #+#             */
/*   Updated: 2024/12/05 18:03:03 by vkinsfat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_file_error(char *argument)
{
	ft_putstr_fd("minishell: ", 2);
	perror(argument);
}

int	open_files(char *filename, int redir_type, int is_input)
{
	int	res;

	res = 0;
	if (is_input == 1 && redir_type == STDIN)
		res = open(filename, O_RDONLY, 0644);
	else if (is_input == 1 && redir_type == HEREDOC)
		res = open(filename, O_RDWR | O_CREAT | O_TRUNC, 0644);
	else if (is_input == 0 && redir_type == STDOUT)
		res = open(filename, O_RDWR | O_CREAT | O_TRUNC, 0644);
	else if (is_input == 0 && redir_type == APPEND)
		res = open(filename, O_RDWR | O_CREAT | O_APPEND, 0644);
	return (res);
}

static int	stdin_processing(t_cmd *cmd, int i)
{
	if (access(cmd->infile_name[i], F_OK) == -1)
		return (print_file_error(cmd->infile_name[i]), FAILURE);
	cmd->infile_fd = open_files(cmd->infile_name[i],
			cmd->input_redir_type[i], 1);
	if (access(cmd->infile_name[i], R_OK) == -1)
		return (print_file_error(cmd->infile_name[i]), FAILURE);
	return (SUCCESS);
}

int	manage_infiles(t_cmd *cmd)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (++i < cmd->num_of_infiles)
	{
		if (cmd->input_redir_type[i] == STDIN)
		{
			if (stdin_processing(cmd, i) == FAILURE)
				return (FAILURE);
		}
		if (cmd->input_redir_type[i] == HEREDOC)
		{
			cmd->infile_fd = open_files("here_doc.txt", HEREDOC, 1);
			if (rwr_heredoc(cmd, cmd->delim[j]) == FAILURE)
				return (FAILURE);
			j++;
		}
		if (i < cmd->num_of_infiles - 1)
			close(cmd->infile_fd);
	}
	return (SUCCESS);
}
