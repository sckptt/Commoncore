/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkinsfat <vkinsfat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 16:14:11 by vitakinsfat       #+#    #+#             */
/*   Updated: 2024/12/02 19:33:36 by vkinsfat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	get_type_of_relative_path(t_cmd *cmd)
{
	size_t	len;

	len = ft_strlen(cmd->argv[1]);
	if (ft_strncmp(cmd->argv[1], ".", len) == 0)
		return (1);
	else if (ft_strncmp(cmd->argv[1], "..", len) == 0)
		return (2);
	else if (ft_strncmp(cmd->argv[1], "--", len) == 0)
		return (3);
	else if (ft_strncmp(cmd->argv[1], "~", len) == 0)
		return (4);
	else if (ft_strncmp(cmd->argv[1], "~/", len) == 0)
		return (4);
	else if (ft_strncmp(cmd->argv[1], "../", 3) == 0)
		return (5);
	else if (ft_strncmp(cmd->argv[1], "/", 1) != 0)
		return (6);
	return (0);
}

static int	update_envs(char *cwd, t_env *env)
{
	char	new_pwd[1024];

	if (getcwd(new_pwd, 1024) == NULL)
		return (perror("minishell: cd"), FAILURE);
	free_and_renew_env_value(env, "OLDPWD", cwd);
	free_and_renew_env_value(env, "PWD", new_pwd);
	return (SUCCESS);
}

static char	*relative_path_preparation(t_cmd *cmd, t_env *env)
{
	char	*path;
	int		type;

	path = NULL;
	type = get_type_of_relative_path(cmd);
	if (type == 1 || type == 2 || type == 5 || type == 6)
	{
		path = ft_strdup(cmd->argv[1]);
		if (!path)
			return (ft_putstr_fd(ALLOC_ERROR, 2), NULL);
	}
	else if (type == 3)
	{
		path = ft_get_env(env, "OLDPWD");
		if (!path)
			return (NULL);
	}
	else if (type == 4)
	{
		path = ft_get_env(env, "HOME");
		if (!path)
			return (NULL);
	}
	return (path);
}

int	ft_cd(t_cmd *cmd, t_env *env)
{
	char	cwd[1024];
	char	*path;

	path = NULL;
	if (cmd->argc == 1)
		return (ft_putstr_fd(CD_ONE_ARG, 2), FAILURE);
	else if (cmd->argc > 2)
		return (ft_putstr_fd(CD_TOO_MANY_ARG_ERROR, 2), FAILURE);
	if (getcwd(cwd, 1024) == NULL)
		return (perror("minishell: cd"), FAILURE);
	if (cmd->argv[1] && cmd->argv[1][0] == '/')
		path = ft_strdup(cmd->argv[1]);
	else if (cmd->argv[1] && cmd->argv[1][0] != '/')
	{
		path = relative_path_preparation(cmd, env);
		if (!path)
			return (perror("minishell: cd"), FAILURE);
	}
	if (chdir(path) == -1)
		return (perror("minishell: cd"), FAILURE);
	if (get_type_of_relative_path(cmd) != 1)
		update_envs(cwd, env);
	free(path);
	return (SUCCESS);
}
