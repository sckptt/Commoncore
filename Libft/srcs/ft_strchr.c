/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkinsfat <vkinsfat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 18:15:46 by vkinsfat          #+#    #+#             */
/*   Updated: 2024/02/14 18:16:52 by vkinsfat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

char	*ft_strchr(char *str, char c)
{
	while (*str)
	{
		if (*str == c)
			return (str);
		else
			str++;
	}
	return (NULL);
}

/*int main(void)
{
	char *str = "hello";
	char a = 'l';
	char b = '.'; 
	printf("%s\n", ft_strchr(str, a));
	printf("%s\n", ft_strchr(str, b));
	printf("%s\n", strchr(str, a));
	printf("%s\n", strchr(str, b));
}*/
