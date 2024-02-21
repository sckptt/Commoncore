/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkinsfat <vkinsfat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 16:04:44 by vkinsfat          #+#    #+#             */
/*   Updated: 2024/02/21 16:56:34 by vkinsfat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (i);
}

int	is_startset(char const *s1, char const *set)
{
	int	i;
	int	lenset;

	i = 0;
	lenset = ft_strlen(set);
	while (lenset--)
	{
		if (s1[i] == set[i])
			i++;
		else
			return (0);
	}
	return (1);
}

int	is_endset(char const *s1, char const *set)
{
	int	i;
	int	lenset;
	int	len;

	i = 0;
	lenset = ft_strlen(set);
	len = ft_strlen(s1);
	while (lenset--)
	{
		if (s1[len - lenset - 1] == set[i])
			i++;
		else
			return (0);
	}
	return (1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	size_t	i;
	size_t	lenset;

	res = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	lenset = ft_strlen(set);
	if (!res)
		return (NULL);
	i = 0;
	if (!is_startset(s1, set) && !is_endset(s1, set))
		ft_strlcpy(res, s1, ft_strlen(s1));
	else
	{
		if (is_startset(s1, set))
		{
			while (i < lenset)
				i++;
		}
		if (is_endset(s1, set))
		{
			while (i < ft_strlen(s1) - lenset)
			{
				res[i] = s1[i];
				i++;
			}
		}
		else
		{
			res[i] = s1[i];
			i++;
		}
	}
	res[i] = '\0';
	return (res);
}

int main(void)
{
	char *str = "   Hello World   ";
	char *set = "   ";
	char *res = ft_strtrim(str, set);
	printf("%s", res);
	printf("%s", ft_strtrim("    Hello world    ", set));
	printf("%s", ft_strtrim("Hello world", set));
	return (0);
}
