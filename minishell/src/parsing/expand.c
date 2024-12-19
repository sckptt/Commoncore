/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   expand.c										   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: arch <arch@student.42.fr>				  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/10/29 22:36:37 by vitakinsfat	   #+#	#+#			 */
/*   Updated: 2024/11/30 21:55:03 by arch			 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "minishell.h"

int	handle_quotes_flag(char c, int flag)
{
	if (c == '\'')
		flag = !flag;
	return (flag);
}

char	*get_env_var(char *str, int *i_ptr, t_env *env, t_env *exit_status)
{
	int		start;
	char	*key;
	char	*temp;

	start = *i_ptr;
	(*i_ptr)++;
	while (str[*i_ptr] && is_env_symbol(str[*i_ptr]))
	{
		if (str[*i_ptr] == '?')
		{
			(*i_ptr)++;
			break ;
		}
		(*i_ptr)++;
	}
	key = ft_substr(str, start, *i_ptr - start);
	temp = expand_env_var(key, env, exit_status);
	free(key);
	return (temp);
}

void	expand_token_value(t_token *current, char *new_value)
{
	if (current->value)
		free(current->value);
	current->value = ft_strdup(new_value);
	if (new_value)
		free(new_value);
}

int	expand_token(t_token *c, t_env *env, t_env *exit_status)
{
	int		i;
	int		f;
	char	*new_value;
	char	*temp;

	i = 0;
	f = 0;
	new_value = NULL;
	while (c->value[i])
	{
		f = handle_quotes_flag(c->value[i], f);
		if (c->value[i] == '$' && c->value[i + 1] && ef(c->value[i + 1]) && !f)
		{
			temp = get_env_var(c->value, &i, env, exit_status);
			new_value = expand_strjoin(new_value, temp);
			free(temp);
		}
		else
		{
			new_value = append_char(new_value, c->value[i]);
			i++;
		}
	}
	expand_token_value(c, new_value);
	return (SUCCESS);
}

int	new_expand_tokens(t_token *first_token, t_env *env, t_env *exit_status)
{
	t_token	*current;

	current = first_token;
	while (current)
	{
		if (current->value && ft_strchr(current->value, '$'))
			expand_token(current, env, exit_status);
		current = current->next;
	}
	return (SUCCESS);
}
