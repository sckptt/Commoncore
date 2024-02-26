/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkinsfat <vkinsfat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 15:01:18 by vkinsfat          #+#    #+#             */
/*   Updated: 2024/02/26 13:07:34 by vkinsfat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "libft.h"

char	*ft_strdup(const char *str)
{
	int		size;
	int		i;
	char	*dup;

	i = 0;
	while (str[i] != '\0')
		i++;
	size = i + 1;
	dup = (char *) malloc(size);
	i = 0;
	while (str[i] != '\0')
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

int	check_length(int n)
{
	int	length;

	length = 0;
	if (n <= 0)
		length = 1;
	while (n != 0)
	{
		n = n / 10;
		length++;
	}
	return (length);
}

char	*ft_itoa(int n)
{
	char	*res;
	int		length;
	int		num;
	int		neg;

	length = check_length(n);
	res = (char *)malloc(sizeof(char) * (length + 1));
	if (!res)
		return (NULL);
	num = n;
	neg = n < 0;
	if (n == -2147483648)
	{
		res = ft_strdup("-2147483648");
		res[length] = '\0';
		return (res);
	}
	if (neg)
		num = -n;
	while (length-- > 0)
	{
		res[length] = num % 10 + '0';
		num = num / 10;
	}
	if (neg)
		res[0] = '-';
	res[check_length(n)] = '\0';
	return (res);
}

// int main (void)
// {
// 	int n = -2147483648;
// 	printf("%s\n", ft_itoa(n));
// 	printf("%s\n", ft_itoa(-25));
// 	printf("%s\n", ft_itoa(0));
// 	printf("%s\n", ft_itoa(2147483647));
// 	printf("%s\n", ft_itoa(214));
// 	return (0);
// }