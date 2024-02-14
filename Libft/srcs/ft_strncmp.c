/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkinsfat <vkinsfat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 18:33:12 by vkinsfat          #+#    #+#             */
/*   Updated: 2024/02/14 18:33:13 by vkinsfat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	if (n <= 0)
	{
		return (0);
	}
	while (s1[i] - s2[i] == 0)
	{
		if (s1[i] == '\0' && s2[i] == '\0')
		{
			return (0);
		}
		i++;
		if (i == n)
		{
			return (0);
		}
	}
	return (s1[i] - s2[i]);
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
