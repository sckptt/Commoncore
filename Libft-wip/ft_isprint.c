/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkinsfat <vkinsfat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 17:02:25 by vkinsfat          #+#    #+#             */
/*   Updated: 2024/02/15 17:38:34 by vkinsfat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <stdio.h>
#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	else
		return (0);
}

/*int	main(void)
{
    char ch = 'S';
    int a = 1;

	printf("%d\n", isprint(ch));
	printf("%d\n", isprint(a));
	printf("%d\n", isprint('\n'));
	printf("%d\n", ft_isprint(ch));
	printf("%d\n", ft_isprint(a));
	printf("%d\n", ft_isprint('\n'));
	return (0);
}*/
