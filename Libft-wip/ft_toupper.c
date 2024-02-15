/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkinsfat <vkinsfat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 17:35:18 by vkinsfat          #+#    #+#             */
/*   Updated: 2024/02/15 17:38:56 by vkinsfat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <stdio.h>
#include "libft.h"

char	ft_toupper(char c)
{
	if (c >= 'a' && c <= 'z')
		c = c - 32;
	return (c);
}

/*int main(void)
{
	char a;
    char b;
    char c;

    a = 'A';
    b = 'b';
    c = '9';
    printf("%c\n", ft_toupper(a));
	printf("%c\n", ft_toupper(b));
    printf("%c\n", ft_toupper(c));
    printf("%c\n", toupper(a));
    printf("%c\n", toupper(b));
	printf("%c\n", toupper(c));
	return (0);
}*/