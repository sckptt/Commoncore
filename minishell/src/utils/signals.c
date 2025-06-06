/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitakinsfator <vitakinsfator@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by                   #+#    #+#             */
/*   Updated: 2025/03/11 12:26:24 by vitakinsfat      ###   ########.fr       */
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
