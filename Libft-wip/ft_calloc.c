/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkinsfat <vkinsfat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 18:27:05 by vkinsfat          #+#    #+#             */
/*   Updated: 2024/02/16 19:54:44 by vkinsfat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

/*void	*ft_bzero(void *ptr, size_t size)
{
	unsigned char	*res;

	res = ptr;
	while (size)
	{
		*res = '!';
		res++;
		size--;
	}
	return (ptr);
}*/

void	*ft_calloc(size_t noe, size_t esize)
{
	void	*ptr;

	ptr = malloc(noe * esize);
	if(ptr == NULL)
		return (NULL);
	ft_bzero(ptr, noe * esize);
	return (ptr);
}

/*int	main(void)
{
	int *test;
	int i = 0;
	
	test = (int *)ft_calloc(5, sizeof(int));
	while (test[i] != '\0')
	{
		printf("%c\n", test[i]);
		i++;
	}
	return (0);
}*/
