/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkinsfat <vkinsfat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 15:20:55 by vkinsfat          #+#    #+#             */
/*   Updated: 2024/03/04 17:55:20 by vkinsfat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_puthexl_fd(int n, int fd)
{
	char			*hex;
	unsigned int	num;

	hex = "0123456789abcdef";
	num = n;
	if (num == 0)
	{
		ft_putchar_fd('0', fd);
		return ;
	}
	if (num < 16)
		ft_putchar_fd(hex[num], fd);
	else
	{
		ft_puthexl_fd(num / 16, fd);
		ft_putchar_fd(hex[num % 16], fd);
	}
}

// void	ft_puthexl_fd(int n, int fd)
// {
// 	ft_putchar_fd('0', fd);
// 	ft_putchar_fd('x', fd);
// 	ft_puthexnum_fd(n, fd);
// }