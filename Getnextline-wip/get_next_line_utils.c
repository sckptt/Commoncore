/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkinsfat <vkinsfat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 15:31:31 by vkinsfat          #+#    #+#             */
/*   Updated: 2024/03/18 20:40:35 by vkinsfat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
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

char	*ft_strchr(const char *str, int c)
{
	char	ch;

	ch = (char)c;
	if (ch == '\0')
		return ((char *)str + ft_strlen(str));
	while (*str)
	{
		if (*str == ch)
			return ((char *)str);
		else
			str++;
	}
	return (NULL);
}

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	int		j;
	size_t	destlen;
	size_t	srclen;

	destlen = ft_strlen(dest);
	srclen = ft_strlen(src);
	i = destlen;
	j = 0;
	if (size <= i)
		return (srclen + size);
	while (src[j] != '\0' && i < size - 1)
		dest[i++] = src[j++];
	dest[i] = '\0';
	return (destlen + srclen);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	while (src[i] && i + 1 < size)
	{
		dest[i] = src[i];
		i++;
	}
	if (size != 0)
		dest[i] = '\0';
	while (src[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
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
