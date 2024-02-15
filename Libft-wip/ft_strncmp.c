/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkinsfat <vkinsfat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 18:33:12 by vkinsfat          #+#    #+#             */
/*   Updated: 2024/02/15 19:42:37 by vkinsfat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (n <= 0)
		return (0);
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

/*int main(void)
{
	char	*str1;
	char	*str2;
	char	*str3;
	char	*str4;

	str1 = "Emrakul";
	str2 = "Ulamog";
    str3 = "Hello";
    str4 = "Hellz";
	printf("Reproduced: %d\n", ft_strncmp(str1, str1, 7));
	printf("Reproduced: %d\n", ft_strncmp(str1, str2, 4));
	printf("Reproduced: %d\n", ft_strncmp(str3, str4, 4));
	printf("Reproduced: %d\n", ft_strncmp(str3, str4, 6));
	printf("Original: %d\n", strncmp(str1, str1, 7));
	printf("Original: %d\n", strncmp(str1, str2, 4));
	printf("Original: %d\n", strncmp(str3, str4, 4));
	printf("Original: %d\n", strncmp(str3, str4, 6));
	return (0);
}*/
