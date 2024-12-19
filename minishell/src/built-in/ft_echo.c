/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkinsfat <vkinsfat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 16:13:45 by vitakinsfat       #+#    #+#             */
/*   Updated: 2024/11/26 16:34:33 by vkinsfat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_echo(t_cmd *cmd)
{
	int	i;
	int	is_new_line;

	i = 1;
	is_new_line = 1;
	if (cmd->argc == 1)
		return (printf("\n"), SUCCESS);
	while (i < cmd->argc && cmd->argv[i] != NULL
		&& ft_strcmp(cmd->argv[i], "-n") == 0)
	{
		is_new_line = 0;
		i++;
	}
	while (i < cmd->argc && cmd->argv[i] != NULL)
	{
		printf("%s", cmd->argv[i]);
		if (i < cmd->argc - 1)
			printf(" ");
		i++;
	}
	if (is_new_line == 1)
		printf("\n");
	return (SUCCESS);
}
