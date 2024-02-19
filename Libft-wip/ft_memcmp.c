/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkinsfat <vkinsfat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 18:11:47 by vkinsfat          #+#    #+#             */
/*   Updated: 2024/02/16 18:11:48 by vkinsfat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	unsigned const char	*one;
	unsigned const char	*two;

	one = str1;
	two = str2;
	while (*one - *two == 0)
	{
		if (*one == '\0' && *two == '\0')
		{
			return (0);
		}
		one++;
		two++;
		n--;
		if (n == 0)
			return (0);
	}
	return (*one - *two);
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
	printf("Reproduced: %d\n", ft_memcmp(str1, str1, 7));
	printf("Reproduced: %d\n", ft_memcmp(str1, str2, 4));
	printf("Reproduced: %d\n", ft_memcmp(str3, str4, 4));
	printf("Reproduced: %d\n", ft_memcmp(str3, str4, 6));
	printf("Original: %d\n", memcmp(str1, str1, 7));
	printf("Original: %d\n", memcmp(str1, str2, 4));
	printf("Original: %d\n", memcmp(str3, str4, 4));
	printf("Original: %d\n", memcmp(str3, str4, 6));
	return (0);
}*/
