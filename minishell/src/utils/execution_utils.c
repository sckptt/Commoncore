/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkinsfat <vkinsfat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 18:41:25 by vitakinsfat       #+#    #+#             */
/*   Updated: 2024/11/26 16:49:00 by vkinsfat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_if_builtin(t_cmd cmd)
{
	if (!cmd.argv[0] || cmd.argv[0][0] == '\0')
		return (-1);
	if (ft_strcmp(cmd.argv[0], "cd") == 0)
		return (TRUE);
	else if (ft_strcmp(cmd.argv[0], "echo") == 0)
		return (TRUE);
	else if (ft_strcmp(cmd.argv[0], "env") == 0)
		return (TRUE);
	else if (ft_strcmp(cmd.argv[0], "exit") == 0)
		return (TRUE);
	else if (ft_strcmp(cmd.argv[0], "export") == 0)
		return (TRUE);
	else if (ft_strcmp(cmd.argv[0], "pwd") == 0)
		return (TRUE);
	else if (ft_strcmp(cmd.argv[0], "unset") == 0)
		return (TRUE);
	return (FALSE);
}

void	close_pipes_in_parent(t_list *list)
{
	int	i;

	i = 0;
	while (i < (list->size - 1))
	{
		close(list->exec_data->fd[i][0]);
		close(list->exec_data->fd[i][1]);
		i++;
	}
}

void	init_exec_data(t_list *list)
{
	list->exec_data->num_of_cmd = &list->size;
	list->exec_data->status = 0;
	list->exec_data->fd = NULL;
	list->exec_data->processes = NULL;
}
