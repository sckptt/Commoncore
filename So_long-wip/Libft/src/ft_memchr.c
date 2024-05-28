/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitakinsfator <vitakinsfator@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 20:45:01 by vkinsfat          #+#    #+#             */
/*   Updated: 2024/05/28 19:50:51 by vitakinsfat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memchr(const void *str, int n, size_t size)
{
	const unsigned char	*res;

	res = str;
	while (size)
	{
		if (*res == (unsigned char)n)
			return ((void *)res);
		else
		{
			size--;
			res++;
		}
	}
	return (NULL);
}
