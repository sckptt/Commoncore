/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_parser_utils3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akulikov <akulikov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 19:27:19 by akulikov          #+#    #+#             */
/*   Updated: 2024/12/03 16:06:02 by akulikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_token(int i, t_token *current)
{
	current->pos = i;
	current->is_parsed = 0;
	current->type = 0;
	current->prev = NULL;
	current->next = NULL;
}

size_t	len_of_input_string(char *input)
{
	size_t	i;

	i = 0;
	while (input[i] && !ft_isspace(input[i]))
	{
		if (input[i] == '"' || input[i] == '\'')
			i = handle_len_quotes(input, i);
		else if (input[i] == '<' || input[i] == '>')
		{
			i = handle_len_redirs(input, i);
			break ;
		}
		else if (input[i] == '|')
		{
			i = handle_len_pipes(input, i);
			break ;
		}
		else
		{
			i++;
			if (ft_isspace(input[i]) || is_operator(input + i))
				break ;
		}
	}
	return (i);
}

void	print_syntax_error_message(t_token *token)
{
	ft_putstr_fd(SYNTAX_ERROR, 2);
	ft_putstr_fd(token->value, 2);
	ft_putstr_fd("'\n", 2);
}
