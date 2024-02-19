/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkinsfat <vkinsfat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 20:02:13 by vkinsfat          #+#    #+#             */
/*   Updated: 2024/02/19 16:01:12 by vkinsfat         ###   ########.fr       */
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

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*res;

	if (!s || !len || start > ft_strlen(s))
	{
		res = (char *)malloc(sizeof(char));
		if (!res)
			return (NULL);
		res[0] = '\0';
		return (res);
	}
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (len)
	{
		res[i] = s[start + i];
		i++;
		len--;
	}
	res[i] = '\0';
	return (res);
}

/*int main(void)
{
	char *s = "Hello World";
	printf("%s\n", ft_substr(s, 6, 5));
	printf("%s\n", ft_substr(s, 20, 5));
	printf("%s\n", ft_substr(s, 6, 0));
	// printf("%s\n", substr(s, 6, 5));
	return (0);
}*/
