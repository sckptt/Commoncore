/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkinsfat <vkinsfat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 18:11:47 by vkinsfat          #+#    #+#             */
/*   Updated: 2024/02/23 17:17:57 by vkinsfat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	unsigned const char	*one;
	unsigned const char	*two;

	one = str1;
	two = str2;
	if (n == 0)
		return (0);
	while (n-- > 0)
	{
		if (*one != *two)
			return (*one - *two);
		one++;
		two++;
	}
	return (0);
}
