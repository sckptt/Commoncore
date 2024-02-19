/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkinsfat <vkinsfat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 20:03:13 by vkinsfat          #+#    #+#             */
/*   Updated: 2024/02/19 20:09:47 by vkinsfat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

int count_words(char const *str, char s)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (str[i] != s)
		{
			i++;
		}
		if (str[i] == s || str[i + 1] == '\0')
		{
			count++;
			i++;
		}
	}
	return (count);
}

// char **ft_split(char const *s, char c)
// {

// }

int main()
{
	char *s = "I see a red door and I want to paint it black";
	char *s1 = "Hello";
	char *s2 = "";
	printf("%d\n", count_words(s, ' '));
	printf("%d\n", count_words(s1, ' '));
	printf("%d\n", count_words(s2, ' '));
	return 0;
}