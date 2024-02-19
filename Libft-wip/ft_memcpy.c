/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkinsfat <vkinsfat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 18:48:11 by vkinsfat          #+#    #+#             */
/*   Updated: 2024/02/16 20:19:45 by vkinsfat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*destin;
	const unsigned char	*sour;

	destin = dest;
	sour = src;
	if (!dest && !src)
		return (NULL);
	while (n)
	{
		*destin = *sour;
		destin++;
		sour++;
		n--;
	}
	return (dest);
}

/*int main(void)
{
	char source[20] = "I'm source string";
	char destination1[20] = "I'm dest";
	char destination2[20] = "I'm dest";
	
	printf("Before: %s\n", destination1);
	memcpy(destination1, source, sizeof(source));
	printf("After: %s\n", destination1);
	printf("Re:before: %s\n", destination2);
	ft_memcpy(destination2, source, sizeof(source));
	printf("Re:after: %s\n", destination2);
	return (0);
}*/
