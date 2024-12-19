/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkinsfat <vkinsfat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 16:14:58 by vitakinsfat       #+#    #+#             */
/*   Updated: 2024/11/28 17:13:08 by vkinsfat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	export_no_args(t_env *env)
{
	char	**array_of_keys;
	char	*value;
	int		array_len;
	int		i;

	array_len = get_length_of_env(env);
	array_of_keys = get_an_array_of_keys(env, array_len);
	if (!array_of_keys)
		return (FAILURE);
	sort_an_array(array_of_keys, array_len);
	i = 0;
	while (i < array_len)
	{
		value = ft_get_env(env, array_of_keys[i]);
		if (value)
			printf("declare -x %s=\"%s\"\n", array_of_keys[i], value);
		else
			printf("declare -x %s=''\n", array_of_keys[i]);
		free(value);
		free(array_of_keys[i]);
		i++;
	}
	free(array_of_keys);
	return (SUCCESS);
}

static void	find_and_change(t_env *env, char *key, char *new_value)
{
	t_env	*temp;

	temp = env;
	while (temp)
	{
		if (ft_strcmp(temp->key, key) == 0)
		{
			free(temp->value);
			temp->value = new_value;
			free(key);
			return ;
		}
		temp = temp->next;
	}
	free(key);
	free(new_value);
}

static int	change_value(t_env *env, char *argument)
{
	char	*key;
	char	*new_value;

	key = get_key(argument);
	if (!key)
		return (FAILURE);
	new_value = NULL;
	if (ft_strchr(argument, '=') != NULL)
	{
		new_value = get_value(argument);
		if (!new_value && ft_strchr(argument, '=') != NULL)
			return (free(key), FAILURE);
	}
	find_and_change(env, key, new_value);
	return (SUCCESS);
}

static int	export_with_args(t_cmd *cmd, t_env *env)
{
	int	i;
	int	exit;

	i = 1;
	exit = 0;
	while (i < cmd->argc)
	{
		if (is_valid_var(cmd->argv[i]) == FALSE)
		{
			ft_putstr_fd("minishell: export: '", 2);
			ft_putstr_fd(cmd->argv[i], 2);
			ft_putstr_fd("': not a valid identifier\n", 2);
			exit = 1;
		}
		else
		{
			if (is_in_var(env, cmd->argv[i]) == FALSE)
				create_env_node(&env, cmd->argv[i]);
			else
				change_value(env, cmd->argv[i]);
		}
		i++;
	}
	return (exit);
}

int	ft_export(t_cmd *cmd, t_env *env)
{
	int	exit;

	exit = 0;
	if (cmd->argc == 1)
		exit = export_no_args(env);
	else if (cmd->argc > 1)
		exit = export_with_args(cmd, env);
	return (exit);
}
