/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkinsfat <vkinsfat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 18:12:11 by vkinsfat          #+#    #+#             */
/*   Updated: 2024/02/23 19:34:17 by vkinsfat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int	i;
	char ch;

	i = 0;
	ch = (char)c;
	while (str[i])
		i++;
	while (i >= 0)
	{
		if (str[i] == ch)
			return ((char *)str + i);
		else
			i--;
	}
	return (NULL);
}
