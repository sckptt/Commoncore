/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akulikov <akulikov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 17:07:59 by akulikov          #+#    #+#             */
/*   Updated: 2024/12/03 17:09:05 by akulikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	count_amount_of_redirections(t_cmd *cmd, t_token *current)
{
	while (is_cmd_end(current) == FALSE && current->next != NULL)
	{
		if (current->type == STDIN || current->type == HEREDOC)
		{
			if (current->type == HEREDOC)
				cmd->num_of_delims++;
			cmd->num_of_infiles++;
		}
		if (current->type == STDOUT || current->type == APPEND)
			cmd->num_of_outfiles++;
		current = current->next;
	}
}

void	init_redirections_in_cmd(t_cmd *cmd)
{
	if (cmd->num_of_infiles > 0)
	{
		cmd->input_redir_type = malloc(sizeof(int) * cmd->num_of_infiles);
		cmd->infile_name = malloc(sizeof(char *) * (cmd->num_of_infiles + 1));
	}
	if (cmd->num_of_outfiles > 0)
	{
		cmd->output_redir_type = malloc(sizeof(int) * cmd->num_of_outfiles);
		cmd->outfile_name = malloc(sizeof(char *) * (cmd->num_of_outfiles + 1));
	}
	if (cmd->num_of_delims > 0)
		cmd->delim = malloc(sizeof(char *) * (cmd->num_of_delims + 1));
}
