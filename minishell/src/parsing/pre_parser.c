/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkinsfat <vkinsfat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 14:33:43 by vitakinsfat       #+#    #+#             */
/*   Updated: 2024/12/05 19:03:39 by vkinsfat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// int	is_operator(char *input)
// {
// 	int	i;

// 	i = 0;
// 	if (input[i] == '|')
// 	{
// 		if (input[i + 1] && input[i + 1] == '|')
// 			return (LOGICAL_OR);
// 		else
// 			return (PIPE);
// 	}
// 	else if (input[i] == '<')
// 	{
// 		if (input[i + 1] && input[i + 1] == '<')
// 			return (HEREDOC);
// 		else
// 			return (STDIN);
// 	}
// 	else if (input[i] == '>')
// 	{
// 		if (input[i + 1] && input[i + 1] == '>')
// 			return (APPEND);
// 		else
// 			return (STDOUT);
// 	}
// 	else if (input[i] == '&' && input[i + 1] && input[i + 1] == '&')
// 		return (LOGICAL_AND);
// 	return (WORD);
// }

int	is_operator(char *input)
{
	if (*input == '|')
	{
		if (*(input + 1) && *(input + 1) == '|')
			return (LOGICAL_OR);
		else
			return (PIPE);
	}
	else if (*input == '<')
	{
		if (*(input + 1) && *(input + 1) == '<')
			return (HEREDOC);
		else
			return (STDIN);
	}
	else if (*input == '>')
	{
		if (*(input + 1) && *(input + 1) == '>')
			return (APPEND);
		else
			return (STDOUT);
	}
	else if (*input == '&' && *(input + 1) && *(input + 1) == '&')
		return (LOGICAL_AND);
	return (WORD);
}

int	make_token(char *input, int *start, int token_pos, t_token *current)
{
	size_t	len;
	char	*value;

	init_token(token_pos, current);
	while (ft_isspace(input[*start]))
		(*start)++;
	len = len_of_input_string(input + *start);
	value = malloc(sizeof(char) * (len + 1));
	if (!value)
		return (ft_putstr_fd(ALLOC_ERROR, 2), FAILURE);
	ft_strlcpy(value, input + *start, len + 1);
	current->value = ft_strtrim(value, " ");
	if (!current->value)
		return (ft_putstr_fd(ALLOC_ERROR, 2), FAILURE);
	current->type = is_operator(value);
	free(value);
	*start += (int)len;
	return (SUCCESS);
}

int	run_parsing(char *input, t_appdata *appdata)
{
	int		i;
	int		j;
	t_token	*prev;

	i = -1;
	j = 0;
	prev = NULL;
	appdata->tokens_num = count_tokens(input);
	appdata->tokens = malloc(sizeof(t_token) * appdata->tokens_num);
	if (!appdata->tokens)
		return (ft_putstr_fd(ALLOC_ERROR, 2), FAILURE);
	while (++i < appdata->tokens_num)
	{
		make_token(input, &j, i, &appdata->tokens[i]);
		if (prev != NULL)
		{
			appdata->tokens[i].prev = prev;
			prev->next = &appdata->tokens[i];
		}
		else
			appdata->first_token = &appdata->tokens[i];
		prev = &appdata->tokens[i];
	}
	return (SUCCESS);
}
