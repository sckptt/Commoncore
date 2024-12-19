/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akulikov <akulikov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 17:55:16 by akulikov          #+#    #+#             */
/*   Updated: 2024/12/02 19:55:39 by akulikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	make_commands(t_appdata *appdata, t_list *list, int start, int end)
{
	int		j;
	int		pflag;
	t_token	*cmd_start;
	t_token	*cmd_end;

	j = 0;
	pflag = 0;
	cmd_start = &appdata->tokens[start];
	cmd_end = cmd_start;
	while (cmd_end && cmd_end->pos <= end)
	{
		while (is_cmd_end(cmd_end) == 0 && cmd_end->next != NULL)
			cmd_end = cmd_end->next;
		if (init_cmd(&list->cmd[j++], cmd_start, cmd_end, pflag) == FAILURE)
			return (FAILURE);
		if (cmd_end->type == PIPE)
			pflag = 1;
		list->size++;
		if (cmd_end->next == NULL)
			break ;
		cmd_start = cmd_end->next;
		cmd_end = cmd_start;
	}
	return (SUCCESS);
}

int	make_a_list(t_appdata *appdata, t_list *list, int start, int end)
{
	if (init_the_list(list, start, end) == FAILURE)
		return (FAILURE);
	if (make_commands(appdata, list, start, end) == FAILURE)
		return (FAILURE);
	if (appdata->tokens[end].type == LOGICAL_AND)
		list->and_after = 1;
	else if (appdata->tokens[end].type == LOGICAL_OR)
		list->or_after = 1;
	else
		list->end_after = 1;
	return (SUCCESS);
}

int	make_lists(t_appdata *appdata)
{
	int		i;
	int		start_pos;
	int		end_pos;
	t_token	*current;

	i = -1;
	start_pos = 0;
	current = appdata->first_token;
	while (++i < appdata->lists_num)
	{
		while (is_list_end(current) == FALSE)
			current = current->next;
		end_pos = current->pos;
		if (make_a_list(appdata, &appdata->lists[i], start_pos, end_pos) == 1)
			return (FAILURE);
		start_pos = end_pos + 1;
		current = current->next;
	}
	return (SUCCESS);
}

int	star_check(t_token *token)
{
	t_token	*temp;

	temp = token;
	while (temp)
	{
		if (is_token_redirection(temp) == TRUE)
		{
			if (temp->next->value[0] == '*' && token->next->type != HEREDOC)
			{
				ft_putstr_fd("minishell: *: ambiguous redirect\n", 2);
				return (FALSE);
			}
		}
		temp = temp->next;
	}
	return (TRUE);
}

int	run_lexer(t_appdata *appdata)
{
	if (!appdata->first_token)
		return (SUCCESS);
	if (syntax_check(appdata->first_token) == FALSE)
	{
		appdata->exit_code = 2;
		return (FAILURE);
	}
	if (star_check(appdata->first_token) == FALSE)
	{
		appdata->exit_code = 1;
		return (FAILURE);
	}
	new_expand_tokens(appdata->first_token, appdata->env, appdata->exit_status);
	if (clean_the_quotes(appdata->first_token) == FAILURE)
		return (FAILURE);
	appdata->lists_num = count_lists(appdata);
	appdata->lists = malloc(sizeof(t_list) * appdata->lists_num);
	if (!appdata->lists)
		return (ft_putstr_fd(ALLOC_ERROR, 2), FAILURE);
	if (make_lists(appdata) == FAILURE)
		return (FAILURE);
	if (expand_exec(appdata, appdata->env) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}
