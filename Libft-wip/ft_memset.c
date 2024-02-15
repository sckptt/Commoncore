/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkinsfat <vkinsfat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 18:11:40 by vkinsfat          #+#    #+#             */
/*   Updated: 2024/02/15 20:14:46 by vkinsfat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
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

/*int	main(void)
{
	char	string[20];
	char	string1[20];

	memset(string, '*', 5);
	printf("%s\n", string);
	ft_memset(string1, 'x', 7);	
	printf("%s\n", string1);
	return (0);
}*/
