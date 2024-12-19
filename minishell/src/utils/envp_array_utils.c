/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp_array_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkinsfat <vkinsfat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 17:31:13 by vitakinsfat       #+#    #+#             */
/*   Updated: 2024/12/02 19:26:01 by vkinsfat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	error_free(t_appdata *appdata, int i)
{
	while (--i >= 0)
		free(appdata->envp[i]);
	free(appdata->envp);
}

static int	get_len_of_env(t_env *env)
{
	int		i;
	t_env	*temp;

	i = 0;
	temp = env;
	while (temp)
	{
		i++;
		temp = temp->next;
	}
	return (i);
}

static int	renew_envp_array(t_appdata *appdata, t_env *env)
{
	t_env	*temp;
	int		i;

	i = 0;
	temp = env;
	while (temp)
	{
		appdata->envp[i] = ft_strjoin(temp->key, "=");
		if (!appdata->envp[i])
			return (error_free(appdata, i), ft_putstr_fd(ALLOC_ERROR, 2), 1);
		if (temp->value)
		{
			appdata->envp[i] = gnl_strjoin(appdata->envp[i], temp->value);
			if (!appdata->envp[i])
			{
				error_free(appdata, i);
				return (ft_putstr_fd(ALLOC_ERROR, 2), FAILURE);
			}
		}
		temp = temp->next;
		i++;
	}
	appdata->envp[i] = NULL;
	return (SUCCESS);
}

int	update_envp_array(t_appdata *appdata, t_env *env)
{
	int	len;

	len = get_len_of_env(env);
	free_char_array(appdata->envp);
	appdata->envp = malloc(sizeof(char *) * (len + 1));
	if (!appdata->envp)
		return (ft_putstr_fd(ALLOC_ERROR, 2), FAILURE);
	if (renew_envp_array(appdata, env) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}

int	init_envp_array(t_appdata *appdata, t_env *env)
{
	int	len;

	len = get_len_of_env(env);
	appdata->envp = malloc(sizeof(char *) * (len + 1));
	if (!appdata->envp)
		return (ft_putstr_fd(ALLOC_ERROR, 2), FAILURE);
	if (renew_envp_array(appdata, appdata->env) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}
