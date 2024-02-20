/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkinsfat <vkinsfat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 20:03:13 by vkinsfat          #+#    #+#             */
/*   Updated: 2024/02/20 20:00:30 by vkinsfat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122) || (c >= 48 && c <= 57))
		return (1);
	else
		return (0);
}

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
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] != s && str[i] != '\0')
	{
		count++;
		i++;
	}
	return (count);
}

void	fill_res(char const *str, char s, char **res)
{
	int i;
	int j;
	int len;

	i = 0;
	len = 0;
	while (*str != '\0')
	{
		if (*str != s)
		{
			len = count_letters(str, s);
			printf("%s\n", str);
			res[i] = (char *)malloc(sizeof(char) * (len + 1));
			if (!*res[i])
			{
				while (i > 0)
				{
					free(res[i]);
					i--;
				}
			}
			j = 0;
			while (*str != s && *str != '\0')
			{
				res[i][j] = *str;
				str++;
				j++;
			}
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

int main()
{
	int i = 0;
	char *s = " I   see a red door   and I want        to paint it black  ";
	// int words = count_words(s, ' ');
	// printf("%d\n", words);
	char **res = ft_split(s, ' ');
	while (*res[i])
	{
		printf("%d\n", i);
		printf("%s\n", res[i]);
		i++;
	}
	return 0;
}