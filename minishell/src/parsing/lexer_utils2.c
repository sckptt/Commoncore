/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akulikov <akulikov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 20:06:01 by vitakinsfat       #+#    #+#             */
/*   Updated: 2024/12/02 19:52:55 by akulikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_cmd_end(t_token *token)
{
	if (token->type == PIPE)
		return (TRUE);
	if (token->type == LOGICAL_AND || token->type == LOGICAL_OR)
		return (TRUE);
	return (FALSE);
}

int	is_list_end(t_token *token)
{
	if (token->next == NULL)
		return (TRUE);
	if (token->type == LOGICAL_AND || token->type == LOGICAL_OR)
		return (TRUE);
	return (FALSE);
}

int	is_token_redirection(t_token *token)
{
	if (token->type >= STDIN && token->type <= APPEND)
		return (TRUE);
	return (FALSE);
}

int	count_lists(t_appdata *appdata)
{
	int		res;
	t_token	*current;

	res = 1;
	current = appdata->first_token;
	while (current)
	{
		if (current->type == LOGICAL_AND || current->type == LOGICAL_OR)
			res++;
		current = current->next;
	}
	return (res);
}

int	init_cmd(t_cmd *cmd, t_token *first, t_token *last, int is_pipe_before)
{
	cmd->argc = 0;
	cmd->input_redir_type = 0;
	cmd->output_redir_type = 0;
	cmd->num_of_infiles = 0;
	cmd->num_of_outfiles = 0;
	cmd->num_of_delims = 0;
	cmd->is_pipe_before = 0;
	cmd->is_pipe_after = 0;
	cmd->infile_fd = -1;
	cmd->outfile_fd = -1;
	cmd->argv = NULL;
	cmd->infile_name = NULL;
	cmd->outfile_name = NULL;
	cmd->delim = NULL;
	set_pipes_in_cmd(cmd, is_pipe_before, last);
	set_redirections_in_cmd(cmd, first);
	if (set_the_command_itself(cmd, first) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}
