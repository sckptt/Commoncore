/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkinsfat <vkinsfat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 18:12:11 by vkinsfat          #+#    #+#             */
/*   Updated: 2024/02/16 18:28:08 by vkinsfat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"

char	*ft_strrchr(const char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	while (i >= 0)
	{
		if (str[i] == c)
			return ((char *)str + i);
		else
			i--;
	}
	return (NULL);
}

/*int main(void)
{
	char *str = "religious/desicious";
	char a = 'l';
	char b = 'i'; 
	printf("%s\n", ft_strrchr(str, a));
	printf("%s\n", ft_strrchr(str, b));
	printf("%s\n", strrchr(str, a));
	printf("%s\n", strrchr(str, b));
}*/
