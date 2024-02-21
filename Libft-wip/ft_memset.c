/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkinsfat <vkinsfat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 18:11:40 by vkinsfat          #+#    #+#             */
/*   Updated: 2024/02/21 16:51:36 by vkinsfat         ###   ########.fr       */
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
