/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkinsfat <vkinsfat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 18:16:40 by vkinsfat          #+#    #+#             */
/*   Updated: 2024/02/15 17:38:51 by vkinsfat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <stdio.h>
#include "libft.h"

char	ft_tolower(char c)
{
	if (c >= 'A' && c <= 'Z')
		c = c + 32;
	return (c);
}

/*int main(void)
{
	char a;
    char b;
    char c;

    a = 'Z';
    b = 'y';
    c = '+';
    printf("%c\n", ft_tolower(a));
	printf("%c\n", ft_tolower(b));
    printf("%c\n", ft_tolower(c));
    printf("%c\n", tolower(a));
    printf("%c\n", tolower(b));
	printf("%c\n", tolower(c));
	return (0);
}*/