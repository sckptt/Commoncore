/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitakinsfator <vitakinsfator@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 15:09:31 by vitakinsfat       #+#    #+#             */
/*   Updated: 2024/10/11 14:50:15 by vitakinsfat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_get_env(t_env *env, char *key)
{
	t_env	*temp;
	char	*value;

	if (!env || !key)
		return (NULL);
	temp = env;
	while (temp != NULL)
	{
		if (ft_strcmp(temp->key, key) == 0)
		{
			if (!temp->value)
				return (NULL);
			value = ft_strdup(temp->value);
			if (!value)
				return (ft_putstr_fd(ALLOC_ERROR, 2), NULL);
			return (value);
		}
		temp = temp->next;
	}
	return (NULL);
}

void	free_and_renew_env_value(t_env *env, char *key, char *new_value)
{
	t_env	*temp;

	temp = env;
	while (temp != NULL)
	{
		if (ft_strncmp(temp->key, key, ft_strlen(key)) == 0)
		{
			free(temp->value);
			temp->value = ft_strdup(new_value);
			return ;
		}
		temp = temp->next;
	}
}

void	print_env(t_env *env, char *key)
{
	t_env	*temp;

	temp = env;
	while (temp != NULL)
	{
		if (ft_strncmp(temp->key, key, ft_strlen(key)) == 0)
		{
			printf("%s is %s\n", key, temp->value);
			return ;
		}
		temp = temp->next;
	}
}
