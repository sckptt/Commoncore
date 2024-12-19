/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akulikov <akulikov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 15:59:54 by vitakinsfat       #+#    #+#             */
/*   Updated: 2024/12/03 19:42:44 by akulikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_tokens(t_appdata *appdata)
{
	int	i;

	i = -1;
	while (++i < appdata->tokens_num)
	{
		if (appdata->tokens[i].value)
		{
			free(appdata->tokens[i].value);
			appdata->tokens[i].value = NULL;
		}
	}
	free(appdata->tokens);
	appdata->tokens = NULL;
	appdata->first_token = NULL;
}

void	free_memory(t_appdata *appdata)
{
	int	i;

	if (!appdata)
		return ;
	if (appdata->lists && appdata->lists_num > 0)
	{
		i = -1;
		while (++i < appdata->lists_num)
			free_lists(&appdata->lists[i]);
		free(appdata->lists);
		appdata->lists_num = 0;
	}
	if (appdata->tokens && appdata->tokens_num > 0)
		free_tokens(appdata);
}

void	free_env(t_env *env)
{
	t_env	*temp;

	if (!env)
		return ;
	while (env)
	{
		temp = env;
		env = env->next;
		if (temp->key)
			free(temp->key);
		if (temp->value)
			free(temp->value);
		free(temp);
	}
	env = NULL;
}

void	free_char_array(char **array)
{
	int	i;

	i = 0;
	if (!array)
		return ;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
	array = NULL;
}

void	free_sh1t(t_appdata *appdata)
{
	free_env(appdata->env);
	free_env(appdata->exit_status);
	free_char_array(appdata->envp);
	free_memory(appdata);
}
