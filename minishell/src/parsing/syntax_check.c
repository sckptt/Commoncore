/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akulikov <akulikov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 16:44:13 by vitakinsfat       #+#    #+#             */
/*   Updated: 2024/12/03 16:04:57 by akulikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	pipe_syntax_check(t_token *token)
{
	t_token	*temp;

	temp = token;
	while (temp)
	{
		if (temp->type == PIPE)
		{
			if (temp->pos == 0 || temp->next == NULL
				|| (temp->next->type != WORD
					&& is_token_redirection(temp->next) == FALSE))
			{
				print_syntax_error_message(temp);
				return (FALSE);
			}
			else if (temp->prev != NULL && temp->prev->type != WORD)
			{
				print_syntax_error_message(temp);
				return (FALSE);
			}
		}
		temp = temp->next;
	}
	return (TRUE);
}

int	redirection_syntax_check(t_token *token)
{
	t_token	*temp;

	temp = token;
	while (temp)
	{
		if (is_token_redirection(temp) == TRUE)
		{
			if (temp->next == NULL || temp->next->type != WORD)
			{
				print_syntax_error_message(temp);
				return (FALSE);
			}
		}
		temp = temp->next;
	}
	return (TRUE);
}

int	or_check(t_token *token)
{
	t_token	*temp;

	temp = token;
	while (temp)
	{
		if (temp->type == LOGICAL_OR)
		{
			if (temp->pos == 0 || temp->next == NULL
				|| (temp->next->type != WORD
					&& is_token_redirection(temp->next) == FALSE))
			{
				print_syntax_error_message(temp);
				return (FALSE);
			}
			else if (temp->prev != NULL && temp->prev->type != WORD)
			{
				print_syntax_error_message(temp);
				return (FALSE);
			}
		}
		temp = temp->next;
	}
	return (TRUE);
}

int	and_check(t_token *token)
{
	t_token	*temp;

	temp = token;
	while (temp)
	{
		if (temp->type == LOGICAL_AND || temp->value[0] == '&')
		{
			if (temp->pos == 0 || temp->next == NULL
				|| (temp->next->type != WORD
					&& is_token_redirection(temp->next) == FALSE))
			{
				print_syntax_error_message(temp);
				return (FALSE);
			}
			else if (temp->prev != NULL && temp->prev->type != WORD)
			{
				print_syntax_error_message(temp);
				return (FALSE);
			}
		}
		temp = temp->next;
	}
	return (TRUE);
}

int	syntax_check(t_token *token)
{
	if (or_check(token) == FALSE)
		return (FALSE);
	else if (and_check(token) == FALSE)
		return (FALSE);
	else if (pipe_syntax_check(token) == FALSE)
		return (FALSE);
	else if (redirection_syntax_check(token) == FALSE)
		return (FALSE);
	return (TRUE);
}
