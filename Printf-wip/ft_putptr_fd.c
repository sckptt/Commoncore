/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkinsfat <vkinsfat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 14:18:20 by vkinsfat          #+#    #+#             */
/*   Updated: 2024/03/04 17:56:44 by vkinsfat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_puthex_fd(unsigned long n, int fd)
{
	char	*hex;

	hex = "0123456789abcdef";
	if (n == 0)
	{
		ft_putchar_fd('0', fd);
		return ;
	}
	if (n < 16)
		ft_putchar_fd(hex[n], fd);
	else
	{
		ft_puthex_fd(n / 16, fd);
		ft_putchar_fd(hex[n % 16], fd);
	}
}

void	ft_putptr_fd(void *ptr, int fd)
{
	ft_putchar_fd('0', fd);
	ft_putchar_fd('x', fd);
	ft_puthex_fd((unsigned long)&ptr, fd);
}
