/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkinsfat <vkinsfat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 18:48:05 by vkinsfat          #+#    #+#             */
/*   Updated: 2024/02/21 16:49:43 by vkinsfat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_bzero(void *ptr, size_t size)
{
	unsigned char	*res;

	res = ptr;
	while (size)
	{
		*res = '\0';
		res++;
		size--;
	}
	return (ptr);
}
