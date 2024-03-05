/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkinsfat <vkinsfat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 15:20:55 by vkinsfat          #+#    #+#             */
/*   Updated: 2024/03/05 15:07:17 by vkinsfat         ###   ########.fr       */
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
