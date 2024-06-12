/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitakinsfator <vitakinsfator@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 18:27:05 by vkinsfat          #+#    #+#             */
/*   Updated: 2024/05/28 19:49:09 by vitakinsfat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_calloc(size_t noe, size_t esize)
{
	void	*ptr;

	if (esize && noe > (SIZE_MAX / esize))
		return (NULL);
	ptr = malloc(noe * esize);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, noe * esize);
	return (ptr);
}
