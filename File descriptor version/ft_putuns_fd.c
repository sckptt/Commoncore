/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuns_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitakinsfator <vitakinsfator@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 15:43:33 by vkinsfat          #+#    #+#             */
/*   Updated: 2024/03/05 17:32:14 by vitakinsfat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putuns_fd(unsigned long n, int fd)
{
	if (n >= 10)
	{
		ft_putuns_fd(n / 10, fd);
		ft_putuns_fd(n % 10, fd);
	}
	else
		ft_putchar_fd(n + '0', fd);
}
