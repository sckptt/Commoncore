/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitakinsfator <vitakinsfator@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by                   #+#    #+#             */
/*   Updated: 2025/03/11 12:23:22 by vitakinsfat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minishell.h"

static int	execute_multiple(t_appdata *appdata, t_list *list)
{
	if (prepare_pipes(list) == FAILURE)
	{
		list->exec_data->status = 1;
		return (FAILURE);
	}
	if (create_processes(appdata, list) == FAILURE)
	{
		list->exec_data->status = 1;
		return (FAILURE);
	}
	if (wait_for_children(list) == FAILURE)
	{
		list->exec_data->status = 1;
		return (FAILURE);
	}
	return (SUCCESS);
}

static int	execute_a_list(t_appdata *appdata, t_list *list)
{
	int	i;

	i = -1;
	while (++i < list->size)
	{
		if (list->cmd[i].argc > 0)
			list->cmd[i].is_builtin = check_if_builtin(list->cmd[i]);
	}
	if (file_manager(list) == FAILURE)
	{
		if (g_sig_received)
		{
			g_sig_received = 0;
			list->exec_data->status = 130;
		}
		return (FAILURE);
	}
	if (list->size > 1)
	{
		if (execute_multiple(appdata, list) == FAILURE)
			return (FAILURE);
	}
	else if (list->size == 1)
		execute_single(appdata, list);
	return (SUCCESS);
}

void	start_execution(t_appdata *appdata)
{
	int	i;

	i = 1;
	signal(SIGINT, func_int);
	execute_a_list(appdata, &appdata->lists[0]);
	while (i < appdata->lists_num)
	{
		if (appdata->should_exit == TRUE)
			new_cycle_preparation(appdata);
		if (appdata->lists[i - 1].and_after == TRUE)
		{
			if (appdata->lists[i - 1].exec_data->status == SUCCESS)
				execute_a_list(appdata, &appdata->lists[i]);
		}
		else if (appdata->lists[i - 1].or_after == TRUE)
		{
			if (appdata->lists[i - 1].exec_data->status != SUCCESS)
				execute_a_list(appdata, &appdata->lists[i]);
		}
		i++;
	}
}
