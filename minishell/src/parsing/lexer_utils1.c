/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arch <arch@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 20:05:54 by vitakinsfat       #+#    #+#             */
/*   Updated: 2024/12/04 21:19:57 by arch             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	set_std_redir(t_cmd *cmd, t_token *current, int *in_i, int *out_i)
{
	if (current->type == STDIN)
	{
		if (*in_i >= cmd->num_of_infiles)
			return ;
		cmd->input_redir_type[*in_i] = STDIN;
		cmd->infile_name[*in_i] = ft_strdup(current->next->value);
		cmd->infile_name[*in_i + 1] = NULL;
		(*in_i)++;
	}
	else if (current->type == STDOUT)
	{
		cmd->output_redir_type[*out_i] = STDOUT;
		cmd->outfile_name[*out_i] = ft_strdup(current->next->value);
		cmd->outfile_name[*out_i + 1] = NULL;
		(*out_i)++;
	}
}

void	set_heredoc_redir(t_cmd *cmd, t_token *current, int *in_i, int *here_i)
{
	cmd->input_redir_type[*in_i] = HEREDOC;
	cmd->infile_name[*in_i] = ft_strdup("here_doc.txt");
	cmd->delim[*here_i] = ft_strdup(current->next->value);
	cmd->delim[*here_i + 1] = NULL;
	(*in_i)++;
	(*here_i)++;
}

void	set_append_redir(t_cmd *cmd, t_token *current, int *output_i)
{
	cmd->output_redir_type[*output_i] = APPEND;
	cmd->outfile_name[*output_i] = ft_strdup(current->next->value);
	(*output_i)++;
}

void	set_redirections_in_cmd(t_cmd *cmd, t_token *current)
{
	int	input_i;
	int	output_i;
	int	heredoc_i;

	input_i = 0;
	output_i = 0;
	heredoc_i = 0;
	count_amount_of_redirections(cmd, current);
	init_redirections_in_cmd(cmd);
	while (is_cmd_end(current) == FALSE && current->next != NULL)
	{
		if (current->type >= STDIN && current->type <= APPEND)
		{
			if (current->type == STDIN || current->type == STDOUT)
				set_std_redir(cmd, current, &input_i, &output_i);
			else if (current->type == HEREDOC)
				set_heredoc_redir(cmd, current, &input_i, &heredoc_i);
			else if (current->type == APPEND)
				set_append_redir(cmd, current, &output_i);
			current->is_parsed = 1;
			current->next->is_parsed = 1;
		}
		current = current->next;
	}
}

void	set_pipes_in_cmd(t_cmd *cmd, int pipe_flag, t_token *last)
{
	if (pipe_flag == TRUE)
		cmd->is_pipe_before = 1;
	if (last->type == PIPE)
	{
		cmd->is_pipe_after = 1;
		last->is_parsed = 1;
	}
}
