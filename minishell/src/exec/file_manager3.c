/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_manager3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkinsfat <vkinsfat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 17:47:55 by vkinsfat          #+#    #+#             */
/*   Updated: 2024/12/05 21:29:35 by vkinsfat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	reopen_heredoc(t_cmd *cmd)
{
	close(cmd->infile_fd);
	cmd->infile_fd = open("here_doc.txt", O_RDONLY, 0664);
	if (cmd->infile_fd == -1)
	{
		unlink("here_doc.txt");
		return (FAILURE);
	}
	return (SUCCESS);
}

static void	print_ctrld_message(char *delim, char *line)
{
	ft_putstr_fd(HD_CTRLD, 2);
	ft_putstr_fd(delim, 2);
	ft_putstr_fd("')\n", 2);
	free(line);
}

static void	sigint_cleanup(t_cmd *cmd, char *line)
{
	free(line);
	close(cmd->infile_fd);
	unlink("here_doc.txt");
}

int	rwr_heredoc(t_cmd *cmd, char *delim)
{
	char	*line;

	while (1)
	{
		ft_putstr_fd("> ", 1);
		signal(SIGINT, interrupt_heredoc_signal);
		line = get_next_line(0);
		if (g_sig_received)
			return (sigint_cleanup(cmd, line), FAILURE);
		if (line == NULL)
		{
			print_ctrld_message(delim, line);
			break ;
		}
		if (ft_strcmp(line, delim) == 0)
			break ;
		write(cmd->infile_fd, line, ft_strlen(line));
		write(cmd->infile_fd, "\n", 1);
		free(line);
	}
	free(line);
	if (reopen_heredoc(cmd) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}
