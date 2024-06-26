/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkinsfat <vkinsfat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 17:23:49 by vitakinsfat       #+#    #+#             */
/*   Updated: 2024/06/27 17:21:24 by vkinsfat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <errno.h>
# include <sys/wait.h>
# include "../Libft/includes/libft.h"

typedef struct s_pipe_data
{
	char	**cmd1;
	char	**cmd2;
	char	**paths;
	int		fd[2];
	int		infile;
	int		outfile;
	pid_t	process1;
	pid_t	process2;
}	t_pipe_data;

char	*find_paths(char **envp);
char	*make_command(t_pipe_data pipex, char **cmd);

int		open_files(char **av, int is_in);

void	check_args(int ac, char **av);
void	end_programm(t_pipe_data pipex);
void	error_rising(t_pipe_data pipex);

#endif