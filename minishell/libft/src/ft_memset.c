/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akulikov <akulikov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 18:11:40 by vkinsfat          #+#    #+#             */
/*   Updated: 2024/08/29 15:53:40 by akulikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int n, size_t size)
{
	unsigned char	*res;

	res = ptr;
	while (size)
	{
		*res = (unsigned char)n;
		res++;
		size--;
	}
	return (ptr);
}
