/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akulikov <akulikov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 18:54:49 by vkinsfat          #+#    #+#             */
/*   Updated: 2024/08/29 15:53:40 by akulikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
