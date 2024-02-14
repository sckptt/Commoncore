/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkinsfat <vkinsfat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 15:34:45 by vkinsfat          #+#    #+#             */
/*   Updated: 2024/02/14 15:37:49 by vkinsfat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <stdio.h>

int	ft_isalnum(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122) || (c >= 48 && c <= 57))
		return (1);
	else
		return (0);
}

/*int	main(void)
{
    int a = '9';
    char c = 'b';

	printf("%d\n", isalnum(c));
	printf("%d\n", isalnum(a));
	printf("%d\n", isalnum(48));
	printf("%d\n", ft_isalnum(c));
	printf("%d\n", ft_isalnum(a));
	printf("%d\n", ft_isalnum(48));
	return (0);
}*/
