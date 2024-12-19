/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkinsfat <vkinsfat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 22:58:32 by vitakinsfat       #+#    #+#             */
/*   Updated: 2024/12/02 19:28:04 by vkinsfat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_appdata(t_appdata *appdata)
{
	appdata->tokens_num = 0;
	appdata->lists_num = 0;
	appdata->exit_code = 0;
	appdata->should_exit = 0;
	appdata->envp_needs_update = 0;
	appdata->envp = NULL;
	appdata->env = NULL;
	appdata->lists = NULL;
	appdata->tokens = NULL;
	appdata->first_token = NULL;
	appdata->exit_status = NULL;
}

int	increment_shlvl(t_env *env)
{
	t_env	*temp;
	int		num_val;

	temp = env;
	while (temp)
	{
		if (ft_strcmp(temp->key, "SHLVL") == 0)
		{
			num_val = ft_atoi(temp->value);
			num_val++;
			free(temp->value);
			temp->value = ft_itoa(num_val);
			if (!temp->value)
			{
				ft_putstr_fd(ALLOC_ERROR, 2);
				return (FAILURE);
			}
			break ;
		}
		temp = temp->next;
	}
	return (SUCCESS);
}

int	initialization(t_appdata *appdata, char **envp)
{
	init_appdata(appdata);
	if (initialize_env_var(appdata, envp) == FAILURE)
		return (FAILURE);
	if (create_env_node(&appdata->exit_status, "?=0") == FAILURE)
		return (FAILURE);
	if (increment_shlvl(appdata->env) == FAILURE)
		return (FAILURE);
	if (init_envp_array(appdata, appdata->env) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}
