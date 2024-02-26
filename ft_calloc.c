/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkinsfat <vkinsfat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 18:27:05 by vkinsfat          #+#    #+#             */
/*   Updated: 2024/02/26 14:14:45 by vkinsfat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

// void	*ft_bzero(void *ptr, size_t size)
// {
// 	unsigned char	*res;

// 	res = ptr;
// 	while (size)
// 	{
// 		*res = '\0';
// 		res++;
// 		size--;
// 	}
// 	return (ptr);
// }

void	*ft_calloc(size_t noe, size_t esize)
{
	void	*ptr;

	ptr = malloc(noe * esize);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, noe * esize);
	return (ptr);
}

// int main(void)
// {
// 	int *p = calloc(-5, -5);
// 	int *p1 = ft_calloc(-5, -5);
// 	printf("%p\n", p);
// 	printf("%p\n", p1);
// 	return 0;
// }


	// /* 9 */ check(ft_calloc(-5, -5) == NULL); showLeaks();
	// p = ft_calloc(0, -5);
	// /* 11 */ check(p != NULL); free(p); showLeaks();
	// /* 12 */ check(ft_calloc(3, -5) == NULL); showLeaks();
	// /* 13 */ check(ft_calloc(-5, 3) == NULL); showLeaks();