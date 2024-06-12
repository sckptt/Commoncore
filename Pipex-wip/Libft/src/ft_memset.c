/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitakinsfator <vitakinsfator@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 18:11:40 by vkinsfat          #+#    #+#             */
/*   Updated: 2024/05/28 19:51:07 by vitakinsfat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

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
