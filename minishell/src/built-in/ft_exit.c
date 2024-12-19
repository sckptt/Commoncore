/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkinsfat <vkinsfat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 16:15:51 by vitakinsfat       #+#    #+#             */
/*   Updated: 2024/11/07 15:51:48 by vkinsfat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	process_exit_with_arg(t_appdata *appdata, t_cmd *cmd)
{
	long long	exit;

	exit = 0;
	if (!cmd->argv[1] || is_valid_digit(cmd->argv[1]) == FALSE)
	{
		appdata->exit_code = COMMAND_MISUSE;
		ft_putstr_fd("minishell: exit: ", 2);
		ft_putstr_fd(cmd->argv[1], 2);
		ft_putstr_fd(": numeric argument required\n", 2);
	}
	else
	{
		exit = ft_atoll(cmd->argv[1]);
		if (exit < 0 || exit > 255)
			appdata->exit_code = (int)(exit % 256);
		else
			appdata->exit_code = exit;
	}
}

int	ft_exit(t_appdata *appdata, t_cmd *cmd)
{
	ft_putstr_fd("exit\n", 1);
	appdata->should_exit = 1;
	if (cmd->argc == 1)
	{
		appdata->exit_code = SUCCESS;
		return (SUCCESS);
	}
	else if (cmd->argc > 2)
	{
		ft_putstr_fd(EXIT_TOO_MANY_ARG_ERROR, 2);
		appdata->exit_code = FAILURE;
		appdata->should_exit = 0;
		return (FAILURE);
	}
	else
		process_exit_with_arg(appdata, cmd);
	return (SUCCESS);
}
