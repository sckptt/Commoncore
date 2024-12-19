/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkinsfat <vkinsfat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 14:15:13 by vkinsfat          #+#    #+#             */
/*   Updated: 2024/12/05 18:16:40 by vkinsfat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <curses.h>
# include <dirent.h>
# include <errno.h>
# include <fcntl.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdbool.h>
# include <stddef.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <sys/ioctl.h>
# include <sys/types.h>
# include <signal.h>
# include <termios.h>
# include <term.h>
# include <unistd.h>
# include "libft.h"

# define ALLOC_ERROR "Error! The program failed to allocate memory!\n"
# define BUFFER_SIZE 42
# define CD_ONE_ARG "minishell: cd: no absolute or relative path specified\n"
# define CD_TOO_MANY_ARG_ERROR "minishell: cd: too many arguments\n"
# define EXIT_TOO_MANY_ARG_ERROR "minishell: exit: too many arguments\n"
# define SYNTAX_ERROR "minishell: syntax error near unexpected token `"
# define HD_CTRLD "minishell: here-document delimited by end-of-file (wanted `"

# define WORD 0
# define ARGUMENT 1
# define PIPE 2
# define STDIN 3
# define STDOUT 4
# define HEREDOC 5
# define APPEND 6
# define LOGICAL_AND 7
# define LOGICAL_OR 8
# define SINGLE_QUOTE 9
# define DOUBLE_QUOTE 10

# define SUCCESS 0
# define FAILURE 1
# define COMMAND_MISUSE 2
# define COMMAND_NOT_EXECUTABLE 126
# define COMMAND_NOT_FOUND 127
# define INVALID_ARGUMENT 128
# define SIGNAL_EXIT 128

extern int		g_sig_received;

typedef struct s_env
{
	char			*key;
	char			*value;
	struct s_env	*next;
}	t_env;

typedef struct s_token
{
	int				pos;
	int				type;
	int				is_parsed;
	char			*value;
	struct s_token	*prev;
	struct s_token	*next;
}	t_token;

typedef struct s_cmd
{
	int				argc;
	int				is_builtin;
	int				*input_redir_type;
	int				*output_redir_type;
	int				num_of_infiles;
	int				num_of_outfiles;
	int				num_of_delims;
	int				is_pipe_after;
	int				is_pipe_before;
	int				infile_fd;
	int				outfile_fd;
	char			**argv;
	char			**infile_name;
	char			**outfile_name;
	char			**delim;
}	t_cmd;

typedef struct s_exec_data
{
	int				*num_of_cmd;
	int				status;
	int				**fd;
	pid_t			*processes;
}	t_exec_data;

typedef struct s_list
{
	int				and_after;
	int				or_after;
	int				end_after;
	int				size;
	t_cmd			*cmd;
	t_exec_data		*exec_data;
}	t_list;

typedef struct s_appdata
{
	int			tokens_num;
	int			lists_num;
	int			exit_code;
	int			should_exit;
	int			envp_needs_update;
	char		**envp;
	t_token		*tokens;
	t_token		*first_token;
	t_list		*lists;
	t_env		*env;
	t_env		*exit_status;
}	t_appdata;

//built-in
int			ft_cd(t_cmd *cmd, t_env *env);
int			ft_echo(t_cmd *cmd);
int			ft_env(t_env *env);
int			ft_exit(t_appdata *appdata, t_cmd *cmd);
int			ft_export(t_cmd *cmd, t_env *env);
int			ft_pwd(void);
int			ft_unset(t_cmd *cmd, t_env *env);

//built-in utils
char		**get_an_array_of_keys(t_env *env, int len);
char		**sort_an_array(char **array, int len);
int			ft_strcmp(char *first_str, char *second_str);
int			get_length_of_env(t_env *env);
int			is_in_var(t_env *env, char *argument);
int			is_valid_digit(char *str);
int			is_valid_var(char *argument);
long long	ft_atoll(char *str);

//enviromentals
int			create_env_node(t_env **env, char *current_env);
int			initialize_env_var(t_appdata *appdata, char **envp);
int			init_envp_array(t_appdata *appdata, t_env *env);
int			update_envp_array(t_appdata *appdata, t_env *env);

//environmentals utils
char		*ft_get_env(t_env *env, char *key);
char		*get_key(char *current_env);
char		*get_value(char *current_env);
void		free_and_renew_env_value(t_env *env, char *key, char *new_value);
void		print_env(t_env *env, char *key);

//execution
int			execute_single(t_appdata *appdata, t_list *list);
int			open_files(char *filename, int redir_type, int is_input);
int			rwr_heredoc(t_cmd *cmd, char *delim);
int			wait_for_children(t_list *list);
int			create_processes(t_appdata *appdata, t_list *list);
int			prepare_pipes(t_list *list);
void		start_execution(t_appdata *appdata);
void		init_exec_data(t_list *list);

//execution utils
char		*get_next_line(int fd);
char		*gnl_strjoin(char const *s1, char const *s2);
char		*make_path(t_cmd *cmd, char **envp);
int			check_if_builtin(t_cmd cmd);
int			execute_a_builtin(t_appdata *appdata, t_cmd *cmd);
int			file_manager(t_list *list);
int			io_redirection(t_cmd *cmd);
size_t		gnl_strlen(const char *str);
void		close_pipes_in_parent(t_list *list);
void		close_fds(t_cmd *cmd, t_exec_data *exec_data, int current_pipe);
void		print_child_error_message(char *cmd_name);
int			manage_infiles(t_cmd *cmd);
void		pipe_redirection(t_exec_data *exec_data, t_cmd *cmd, int i);

//children
void		first_child(t_appdata *appdata, t_exec_data *exec_data, t_cmd *cmd);
void		last_child(t_appdata *appdata,
				t_exec_data *exec_data, t_cmd *cmd, int i);
void		mid_child(t_appdata *appdata,
				t_exec_data *exec_data, t_cmd *cmd, int i);
void		only_child(t_appdata *appdata, t_cmd *cmd);

//utils for freeing
void		free_env(t_env *env);
void		free_char_array(char **envp);
void		free_exec_data(t_list *list);
void		free_lists(t_list *list);
void		free_memory(t_appdata *appdata);
void		free_sh1t(t_appdata *appdata);
void		exec_error(char *argument);
void		new_cycle_preparation(t_appdata *appdata);

//lexer - urils
char		*handle_num_quotes(char *input);
int			init_the_list(t_list *list, int start, int end);
int			expand_argument(t_cmd *cmd, t_env *env);
int			expand_exec(t_appdata *appdata, t_env *env);
int			count_tokens(char *input);
int			ft_isspace(char c);
int			init_cmd(t_cmd *cmd, t_token *first,
				t_token *last, int is_pipe_before);
int			run_parsing(char *input, t_appdata *appdata);
int			set_the_command_itself(t_cmd *cmd, t_token *first);
size_t		handle_len_quotes(char *input, size_t i);
size_t		handle_len_redirs(char *input, size_t i);
size_t		handle_len_pipes(char *input, size_t i);
size_t		len_of_input_string(char *input);
void		init_token(int i, t_token *current);
void		set_argc(t_cmd *cmd, t_token *first);
void		count_amount_of_redirections(t_cmd *cmd, t_token *current);
void		init_redirections_in_cmd(t_cmd *cmd);

//parser - utils
int			clean_the_quotes(t_token *token);
int			count_lists(t_appdata *appdata);
int			count_quoted_len(t_token *token);
int			handle_env_quotes(t_token *token);
int			is_cmd_end(t_token *token);
int			is_list_end(t_token *token);
int			is_token_redirection(t_token *token);
int			is_quotes_double(t_token *token);
int			is_operator(char *input);
int			run_lexer(t_appdata *appdata);
int			set_the_command_itself(t_cmd *cmd, t_token *first);
int			syntax_check(t_token *token);
void		no_quote_copy(t_token *token, char *str);
void		set_pipes_in_cmd(t_cmd *cmd, int pipe_flag, t_token *last);
void		set_redirections_in_cmd(t_cmd *cmd, t_token *current);
void		print_syntax_error_message(t_token *token);

//expand - utils
char		*expand_env_var(char *key, t_env *env, t_env *exit_status);
int			new_expand_tokens(t_token *first_token,
				t_env *env, t_env *exit_status);
int			ef(int c);
char		*expand_strjoin(char *s1, char *s2);
int			is_env_symbol(int c);
char		*append_char(char *s, char c);

//printing - utils
void		print_tokens(t_appdata *appdata);
void		print_lists(t_appdata *appdata);
void		print_file_error(char *argument);

//init
int			initialization(t_appdata *appdata, char **envp);

//signals
void		sigint_handler(int signum);
void		func_int(int signum);
void		interrupt_heredoc_signal(int signum);

#endif
