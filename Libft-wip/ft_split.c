/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkinsfat <vkinsfat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 20:03:13 by vkinsfat          #+#    #+#             */
/*   Updated: 2024/02/26 15:44:01 by vkinsfat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

int	count_words(char const *str, char s)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (str[i] != s)
		{
			if (str[i + 1] == s || str[i + 1] == '\0')
				count++;
			i++;
		}
		else
			i++;
	}
	return (count);
}

int	count_letters(char const *str, char s)
{
	int	count;

	count = 0;
	while (str[count] != s && str[count] != '\0')
		count++;
	return (count);
}

void	fill_res(char const *str, char s, char **res)
{
	int	i;
	int	j;

	i = 0;
	while (*str != '\0')
	{
		if (*str != s)
		{
			res[i] = (char *)malloc(sizeof(char) * (count_letters(str, s) + 1));
			if (!res[i])
			{
				while (i-- > 0)
					free(res[i]);
				return ;
			}
			j = 0;
			while (*str != s && *str != '\0')
				res[i][j++] = *str++;
			res[i][j] = '\0';
			i++;
		}
		else
			str++;
	}
	res[i] = NULL;
}

char	**ft_split(char const *s, char c)
{
	int		words;
	char	**res;

	if (!s)
		return (NULL);
	words = count_words(s, c);
	if (!words || !s[0])
	{
		res = (char **)malloc(sizeof(char *) * 1);
		res[0] = NULL;
		return (res);
	}
	res = (char **)malloc(sizeof(char *) * (words + 1));
	if (!res)
	{
		free(res);
		return (NULL);
	}
	fill_res(s, c, res);
	return (res);
}
