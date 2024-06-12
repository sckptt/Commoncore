/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitakinsfator <vitakinsfator@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 18:54:49 by vkinsfat          #+#    #+#             */
/*   Updated: 2024/05/28 19:51:01 by vitakinsfat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*destin;
	const unsigned char	*sour;

	destin = (unsigned char *)dest;
	sour = (const unsigned char *)src;
	if (destin < sour)
	{
		while (n--)
			*destin++ = *sour++;
	}
	else if (destin > sour)
	{
		destin += n;
		sour += n;
		while (n--)
			*--destin = *--sour;
	}
	return (dest);
}
