/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitakinsfator <vitakinsfator@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 15:20:55 by vkinsfat          #+#    #+#             */
/*   Updated: 2024/03/05 17:32:55 by vitakinsfat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_puthexl(int n, int *count)
{
	char			*hex;
	unsigned int	num;

	hex = "0123456789abcdef";
	num = n;
	if (num == 0)
	{
		ft_putchar('0', count);
		return ;
	}
	if (num < 16)
		ft_putchar(hex[num], count);
	else
	{
		ft_puthexl(num / 16, count);
		ft_putchar(hex[num % 16], count);
	}
}
