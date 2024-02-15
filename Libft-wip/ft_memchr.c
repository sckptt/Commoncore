/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkinsfat <vkinsfat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 20:45:01 by vkinsfat          #+#    #+#             */
/*   Updated: 2024/02/15 20:45:02 by vkinsfat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"

void	*ft_memchr(const void *str, int n, size_t size)
{
	const unsigned char	*res;

	res = str;
	while (size)
	{
		if (*res == (unsigned char)n)
			return ((void *)res);
		else
		{
			size--;
			res++;
		}
	}
	return (NULL);
}

/*int main(void)
{
	char *str = "voracious";
	char a = 'c';
	char b = 'l'; 
	printf("%s\n", (char *)ft_memchr(str, a, sizeof(str)));
	printf("%s\n", (char *)ft_memchr(str, b, sizeof(str)));
	printf("%s\n", (char *)memchr(str, a, sizeof(str)));
	printf("%s\n", (char *)memchr(str, b, sizeof(str)));
	return (0);
}*/
