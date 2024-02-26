/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkinsfat <vkinsfat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 18:15:46 by vkinsfat          #+#    #+#             */
/*   Updated: 2024/02/23 19:35:23 by vkinsfat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(char *str, int c)
{	
	char ch;

	ch = (char)c;
	if (ch == '\0')
		return (str + ft_strlen(str));
	while (*str)
	{
		if (*str == ch)
			return (str);
		else
			str++;
	}
	return (NULL);
}
