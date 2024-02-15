/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkinsfat <vkinsfat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 19:48:36 by vkinsfat          #+#    #+#             */
/*   Updated: 2024/02/15 20:12:39 by vkinsfat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"

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

/*int main(void)
{
	char source[] = "I'm source string";
	char destination2[] = "I'm hyperdestinative destination";
	size_t len;
	
	printf("Dest before: %s\n", destination2);
	printf("Length of dest: %lu\n", strlen(destination2));
	len = ft_strlcpy(destination2, source, sizeof(source));
	printf("Dest after: %s\n", destination2);
	printf("Length of dest: %zu\n", len);
	return (0);
}*/
