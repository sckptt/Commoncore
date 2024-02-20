/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkinsfat <vkinsfat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 18:11:58 by vkinsfat          #+#    #+#             */
/*   Updated: 2024/02/20 16:47:24 by vkinsfat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (*s1 - *s2 == 0)
	{
		if (*s1 == '\0' && *s2 == '\0')
		{
			return (0);
		}
		s1++;
		s2++;
		n--;
		if (n == 0)
			return (0);
	}
	return (*s1 - *s2);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;

	i = 0;
	if (!haystack && !needle)
		return (NULL);
	if (!*needle)
		return ((char *)haystack);
	while (haystack && len--)
	{
		while (haystack[i] == needle )
	}
	return (NULL);
}

/*int main(void)
{
	char *hay = "hello my friend";
	char *need1 = " my";
	char *need2 = ""; 
	printf("%s\n", ft_strnstr(hay, need1, sizeof(hay)));
	printf("%s\n", ft_strnstr(hay, need2, sizeof(hay)));
	// printf("%d\n", strnstr(hay, need1, sizeof(hay)));
	// printf("%d\n", strnstr(hay, need2, sizeof(hay)));
}*/
