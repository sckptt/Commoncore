/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitakinsfator <vitakinsfator@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 15:10:29 by vkinsfat          #+#    #+#             */
/*   Updated: 2024/03/05 17:33:22 by vitakinsfat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr(char *s, int *count)
{
	int	i;

	i = 0;
	if (s == NULL)
	{
		ft_putstr("NULL", count);
		return ;
	}
	while (s[i] != '\0')
	{
		ft_putchar(s[i], count);
		i++;
	}
}
