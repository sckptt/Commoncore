/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arch <arch@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 20:58:37 by vitakinsfat       #+#    #+#             */
/*   Updated: 2024/11/30 22:05:51 by arch             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*append_char(char *s, char c)
{
	char	*res;
	size_t	len;

	if (s)
		len = ft_strlen(s);
	else
		len = 0;
	res = (char *)malloc(sizeof(char) * (len + 2));
	if (!res)
		return (NULL);
	if (s)
	{
		ft_strlcpy(res, s, len + 1);
		free(s);
	}
	else
		res[0] = '\0';
	res[len] = c;
	res[len + 1] = '\0';
	return (res);
}

char	*expand_strjoin(char *s1, char *s2)
{
	char	*res;
	size_t	len1;
	size_t	len2;

	if (s1)
		len1 = ft_strlen(s1);
	else
		len1 = 0;
	if (s2)
		len2 = ft_strlen(s2);
	else
		len2 = 0;
	res = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (!res)
		return (NULL);
	if (s1)
	{
		ft_strlcpy(res, s1, len1 + 1);
		free((char *)s1);
	}
	else
		res[0] = '\0';
	if (s2)
		ft_strlcat(res, s2, len1 + len2 + 1);
	return (res);
}

int	is_env_symbol(int c)
{
	if (ft_isalnum(c))
		return (TRUE);
	if (c == 95)
		return (TRUE);
	if (c == 63)
		return (TRUE);
	return (FALSE);
}

int	ef(int c)
{
	if (ft_isalpha(c))
		return (TRUE);
	if (c == 95)
		return (TRUE);
	if (c == 63)
		return (TRUE);
	return (FALSE);
}

char	*expand_env_var(char *key, t_env *env, t_env *exit_status)
{
	char	*env_var;

	if (*key == '$')
		key++;
	if (ft_strcmp(key, "?") == 0)
	{
		env_var = ft_get_env(exit_status, key);
		if (!env_var)
			return (NULL);
	}
	else
	{
		if (is_in_var(env, key) == FALSE)
			return (ft_strdup(""));
		env_var = ft_get_env(env, key);
		if (!env_var)
			return (NULL);
	}
	return (env_var);
}
