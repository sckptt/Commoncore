/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkinsfat <vkinsfat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 18:27:05 by vkinsfat          #+#    #+#             */
/*   Updated: 2024/02/26 16:27:05 by vkinsfat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdint.h>
#include "libft.h"

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
