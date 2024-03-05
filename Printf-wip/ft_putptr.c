/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkinsfat <vkinsfat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 14:18:20 by vkinsfat          #+#    #+#             */
/*   Updated: 2024/03/05 16:14:19 by vkinsfat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_puthex(unsigned long n, int *count)
{
	char	*hex;

	hex = "0123456789abcdef";
	if (n == 0)
	{
		ft_putchar('0', count);
		return ;
	}
	if (n < 16)
		ft_putchar(hex[n], count);
	else
	{
		ft_puthex(n / 16, count);
		ft_putchar(hex[n % 16], count);
	}
}

void	ft_putptr(void *ptr, int *count)
{
	ft_putchar('0', count);
	ft_putchar('x', count);
	ft_puthex((unsigned long)ptr, count);
}
