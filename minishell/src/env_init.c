/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akulikov <akulikov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 14:18:09 by vitakinsfat       #+#    #+#             */
/*   Updated: 2024/12/03 19:39:52 by akulikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_key(char *current_env)
{
	char	*key;
	size_t	len;

	len = 0;
	if (ft_strchr(current_env, '=') == NULL)
		len = ft_strlen(current_env);
	else
	{
		while (current_env[len] != '=')
			len++;
	}
	key = malloc(sizeof(char) * (len + 1));
	if (!key)
		return (ft_putstr_fd(ALLOC_ERROR, 2), NULL);
	ft_strlcpy(key, current_env, len + 1);
	return (key);
}

char	*get_value(char *current_env)
{
	char	*value;

	if (ft_strchr(current_env, '=') != NULL)
	{
		value = ft_strchr(current_env, '=');
		if (!value)
			return (NULL);
		return (ft_strdup(value + 1));
	}
	return (NULL);
}

t_env	*fill_the_node(char *current_env)
{
	t_env	*node;

	node = malloc(sizeof(t_env));
	if (!node)
	{
		ft_putstr_fd(ALLOC_ERROR, 2);
		return (NULL);
	}
	node->key = get_key(current_env);
	if (!node->key)
	{
		free(node);
		return (NULL);
	}
	if (ft_strchr(current_env, '=') != NULL)
	{
		node->value = get_value(current_env);
		if (!node->value)
		{
			free(node->key);
			free(node);
			return (NULL);
		}
	}
	return (node);
}

int	create_env_node(t_env **env, char *current_env)
{
	t_env	*node;
	t_env	*last;

	if (!env || !current_env)
		return (FAILURE);
	node = fill_the_node(current_env);
	if (!node)
		return (FAILURE);
	node->next = NULL;
	if (!*env)
	{
		*env = node;
		return (SUCCESS);
	}
	last = *env;
	while (last->next != NULL)
		last = last->next;
	last->next = node;
	return (SUCCESS);
}

int	initialize_env_var(t_appdata *appdata, char **envp)
{
	int	i;

	i = 0;
	appdata->env = NULL;
	while (envp[i])
	{
		if (create_env_node(&appdata->env, envp[i]) == FAILURE)
			return (FAILURE);
		i++;
	}
	return (SUCCESS);
}
