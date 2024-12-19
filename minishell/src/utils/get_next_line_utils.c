/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitakinsfator <vitakinsfator@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 15:11:32 by vitakinsfat       #+#    #+#             */
/*   Updated: 2024/09/23 15:38:37 by vitakinsfat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

size_t	gnl_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*gnl_strjoin(char const *s1, char const *s2)
{
	char	*res;
	size_t	lens1;
	size_t	lens2;

	if (!s2)
		return (NULL);
	if (s1)
		lens1 = ft_strlen(s1);
	else
		lens1 = 0;
	lens2 = ft_strlen(s2);
	res = (char *)malloc(sizeof(char) * (lens1 + lens2 + 1));
	if (!res)
		return (NULL);
	if (s1)
	{
		ft_strlcpy(res, s1, lens1 + 1);
		free((char *)s1);
	}
	else
		res[0] = '\0';
	ft_strlcat(res, s2, lens1 + lens2 + 1);
	return (res);
}
