/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_parser_utils2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akulikov <akulikov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 20:46:25 by vitakinsfat       #+#    #+#             */
/*   Updated: 2024/12/02 19:28:45 by akulikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*handle_redirection_tokens(char *input, int *counter)
{
	int	i;

	i = 0;
	if (input[i] == '<')
	{
		if (input[i + 1] && input[i + 1] == '<')
			i++;
		i++;
	}
	if (input[i] == '>')
	{
		if (input[i + 1] && input[i + 1] == '>')
			i++;
		i++;
	}
	(*counter)++;
	return (input + i);
}

char	*handle_pipe_tokens(char *input, int *counter)
{
	int	i;

	i = 0;
	if (input[i + 1] && input[i + 1] == '|')
		i++;
	i++;
	(*counter)++;
	return (input + i);
}

char	*handle_quotes_token(char *input, int *counter)
{
	input = handle_num_quotes(input);
	if (ft_isspace(*input) || *input == '\0')
		(*counter)++;
	return (input);
}

char	*handle_general_tokens(char *input, int *counter)
{
	input++;
	if (ft_isspace(*input) || *input == '\0' || is_operator(input))
		(*counter)++;
	return (input);
}

int	count_tokens(char *input)
{
	int	i;

	i = 0;
	while (*input)
	{
		while (ft_isspace(*input) && *input)
			input++;
		if (*input == '\0')
			break ;
		while (!ft_isspace(*input) && *input)
		{
			if (*input == '"' || *input == '\'')
				input = handle_quotes_token(input, &i);
			else if (*input == '<' || *input == '>')
				input = handle_redirection_tokens(input, &i);
			else if (*input == '|')
				input = handle_pipe_tokens(input, &i);
			else
				input = handle_general_tokens(input, &i);
		}
	}
	return (i);
}
