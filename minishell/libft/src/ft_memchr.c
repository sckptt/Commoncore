/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akulikov <akulikov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 20:45:01 by vkinsfat          #+#    #+#             */
/*   Updated: 2024/08/29 15:53:40 by akulikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
