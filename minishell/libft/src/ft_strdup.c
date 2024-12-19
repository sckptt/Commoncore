/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akulikov <akulikov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 18:11:20 by vkinsfat          #+#    #+#             */
/*   Updated: 2024/09/26 16:40:16 by akulikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//ft_strdup allocate memory and copy const char *str to the designated place
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
	if (!dup)
		return (NULL);
	i = 0;
	while (str[i] != '\0')
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
