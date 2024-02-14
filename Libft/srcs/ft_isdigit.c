/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkinsfat <vkinsfat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 15:21:15 by vkinsfat          #+#    #+#             */
/*   Updated: 2024/02/14 15:38:15 by vkinsfat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <stdio.h>

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	else
		return (0);
}

/*int	main(void)
{
    int a = '8';
    char c = '1';

	printf("%d\n", isdigit(c));
	printf("%d\n", isdigit(a));
	printf("%d\n", isdigit('='));
	printf("%d\n", ft_isdigit(c));
	printf("%d\n", ft_isdigit(a));
	printf("%d\n", ft_isdigit('='));
	return (0);
}*/
