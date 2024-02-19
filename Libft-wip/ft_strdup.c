/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkinsfat <vkinsfat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 18:11:20 by vkinsfat          #+#    #+#             */
/*   Updated: 2024/02/16 18:11:37 by vkinsfat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *str)
{
	int		size;
	int		i;
	char	*dup;

	i = 0;
	while (str[i] != '\0')
		i++;
	size = i + 1;
	dup = (char *) malloc(size);
	i = 0;
	while (str[i] != '\0')
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

/*int main(void)
{
	char *string;

	string = "I see a red door and I want it painted black";
	printf("Reproduced: %s\n", ft_strdup(string));
	printf("Original: %s\n", strdup(string));
	return (0);
}*/
