/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitakinsfator <vitakinsfator@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 17:08:56 by vkinsfat          #+#    #+#             */
/*   Updated: 2024/03/05 17:32:23 by vitakinsfat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strchr(const char *str, int c)
{
	char	ch;

	ch = (char)c;
	if (ch == '\0')
		return ((char *)str + ft_strlen(str));
	while (*str)
	{
		if (*str == ch)
			return ((char *)str);
		else
			str++;
	}
	return (NULL);
}
