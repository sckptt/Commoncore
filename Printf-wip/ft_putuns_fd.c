/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuns_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkinsfat <vkinsfat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 15:43:33 by vkinsfat          #+#    #+#             */
/*   Updated: 2024/03/04 17:57:11 by vkinsfat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

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
