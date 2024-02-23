/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkinsfat <vkinsfat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 18:11:58 by vkinsfat          #+#    #+#             */
/*   Updated: 2024/02/23 18:39:13 by vkinsfat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!haystack && !needle)
		return (NULL);
	if (!*needle)
		return ((char *)haystack);
	while (haystack[i] != '\0' && i < len)
	{
		if (haystack[i] == needle[j] && i < len)
		{
			while (haystack[i] == needle[i])
			{
				if (i == len)
					return ((char *)haystack);	
			}
		}
		else
			i++;
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
