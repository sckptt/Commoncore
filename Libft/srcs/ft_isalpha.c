/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkinsfat <vkinsfat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 15:11:32 by vkinsfat          #+#    #+#             */
/*   Updated: 2024/02/14 15:42:36 by vkinsfat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <stdio.h>

int	ft_isalpha(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		return (1);
	else
		return (0);
}

/*int	main(void)
{   char ch = 'S';
    int a = 88;

	printf("%d\n", isalpha(ch));
	printf("%d\n", isalpha(a));
	printf("%d\n", isalpha('='));
	printf("%d\n", ft_isalpha(ch));
	printf("%d\n", ft_isalpha(a));
	printf("%d\n", ft_isalpha('='));
	return (0);
}*/
