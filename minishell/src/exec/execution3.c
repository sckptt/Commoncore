/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arch <arch@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 18:56:02 by vkinsfat          #+#    #+#             */
/*   Updated: 2024/11/30 17:04:15 by arch             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	wait_for_children(t_list *list)
{
	int		i;
	pid_t	pid;
	int		status;

	i = 0;
	while (i < list->size)
	{
		pid = waitpid(list->exec_data->processes[i], &status, 0);
		if (pid == -1)
			return (perror("minishell: waitpid"), FAILURE);
		if (i == list->size - 1)
		{
			if (WIFEXITED(status))
				list->exec_data->status = WEXITSTATUS(status);
			else if (WIFSIGNALED(status))
				list->exec_data->status = WTERMSIG(status) + SIGNAL_EXIT;
		}
		i++;
	}
	return (SUCCESS);
}

int	create_processes(t_appdata *appdata, t_list *list)
{
	int	i;

	i = -1;
	list->exec_data->processes = malloc(sizeof(pid_t) * list->size);
	if (!list->exec_data->processes)
		return (ft_putstr_fd(ALLOC_ERROR, 2), FAILURE);
	while (++i < list->size)
	{
		list->exec_data->processes[i] = fork();
		if (list->exec_data->processes[i] == 0)
		{
			if (i == 0)
				first_child(appdata, list->exec_data, &list->cmd[0]);
			else if (i == (list->size - 1))
				last_child(appdata, list->exec_data, &list->cmd[i], i);
			else
				mid_child(appdata, list->exec_data, &list->cmd[i], i);
		}
	}
	close_pipes_in_parent(list);
	return (SUCCESS);
}

int	prepare_pipes(t_list *list)
{
	int	i;

	i = -1;
	list->exec_data->fd = malloc(sizeof(int *) * (list->size - 1));
	if (!list->exec_data->fd)
		return (ft_putstr_fd(ALLOC_ERROR, 2), FAILURE);
	while (++i < (list->size - 1))
	{
		list->exec_data->fd[i] = malloc(sizeof(int) * 2);
		if (!list->exec_data->fd[i])
			return (ft_putstr_fd(ALLOC_ERROR, 2), FAILURE);
		list->exec_data->fd[i][0] = -1;
		list->exec_data->fd[i][1] = -1;
		if (pipe(list->exec_data->fd[i]) == -1)
			return (perror("minishell: pipe"), FAILURE);
	}
	return (SUCCESS);
}
