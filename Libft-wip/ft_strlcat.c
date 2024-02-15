/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkinsfat <vkinsfat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 20:25:11 by vkinsfat          #+#    #+#             */
/*   Updated: 2024/02/15 20:25:25 by vkinsfat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	int		j;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (i < size)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (i);
}

/*int main(void)
{
	char source[] = "of Eldraine!";
	char destination[10] = "Wilds ";
	size_t len;
	
	printf("Dest before: %s\n", destination);
	printf("Length of dest: %lu\n", strlen(destination));
	len = ft_strlcat(destination, source, sizeof(destination));
	printf("Dest after: %s\n", destination);
	printf("Length of dest: %zu\n", len);
	return (0);
}*/
