/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitakinsfator <vitakinsfator@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 18:15:46 by vkinsfat          #+#    #+#             */
/*   Updated: 2024/05/28 19:53:36 by vitakinsfat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

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
