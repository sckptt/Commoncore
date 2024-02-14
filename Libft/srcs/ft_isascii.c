/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkinsfat <vkinsfat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 15:52:07 by vkinsfat          #+#    #+#             */
/*   Updated: 2024/02/14 15:53:08 by vkinsfat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <stdio.h>

int	ft_isascii(int c)
{
	if ((c >= 0 && c <= 127))
		return (1);
	else
		return (0);
}

/*int	main(void)
{
    int a = '8';
    char c = '~';

	printf("%d\n", isascii(c));
	printf("%d\n", isascii(a));
	printf("%d\n", isascii(130));
	printf("%d\n", ft_isascii(c));
	printf("%d\n", ft_isascii(a));
	printf("%d\n", ft_isascii('\0'));
	return (0);
}*/
