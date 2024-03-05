/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexu.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkinsfat <vkinsfat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 18:17:19 by vkinsfat          #+#    #+#             */
/*   Updated: 2024/03/05 15:07:49 by vkinsfat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_puthexu(int n, int *count)
{
	char			*hex;
	unsigned int	num;

	hex = "0123456789ABCDEF";
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
		ft_puthexu(num / 16, count);
		ft_putchar(hex[num % 16], count);
	}
}
