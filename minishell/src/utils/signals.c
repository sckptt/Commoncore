/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkinsfat <vkinsfat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 18:38:36 by akulikov          #+#    #+#             */
/*   Updated: 2024/12/05 17:37:46 by vkinsfat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	sigint_handler(int signum)
{
	(void) signum;
	write(STDOUT_FILENO, "\n", 1);
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
	g_sig_received = 2;
}

void	func_int(int signum)
{
	(void)signum;
	write(1, "\n", 1);
}

void	interrupt_heredoc_signal(int signum)
{
	g_sig_received = signum;
	ioctl(0, TIOCSTI, "\n");
}
