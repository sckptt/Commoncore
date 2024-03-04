/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkinsfat <vkinsfat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 16:45:12 by vkinsfat          #+#    #+#             */
/*   Updated: 2024/03/04 18:00:21 by vkinsfat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	handle_format(va_list args, char format)
{
	void	*ptr;

	if (format == 'c')
		ft_putchar_fd(va_arg(args, char), 1);
	else if (format == 's')
		ft_putstr_fd(va_arg(args, char *), 1);
	else if (format == 'p')
	{
		ptr = va_arg(args, void *);
		if (ptr)
			ft_putptr_fd(ptr, 1);
		ft_putstr_fd("0x0", 1);
	}
	else if (format == 'd' || format == 'i')
		ft_putnbr_fd(va_arg(args, int), 1);
	else if (format == 'u')
		ft_putuns_fd(va_arg(args, unsigned long), 1);
	else if (format == 'x')
		ft_puthexl_fd(va_arg(args, int), 1);
	else if (format == 'X')
		ft_puthexu_fd(va_arg(args, int), 1);
	else if (format == '%')
		ft_putchar_fd('%', 1);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		count;

	va_start(args, str);
	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '%' && ft_strchr("cspdiuxX%", str[i + 1]))
		{
			handle_format(args, str[i + 1]);
			count++;
			i += 2;
		}
		else
		{
			ft_putchar_fd(str[i], 1);
			count++;
			i++;
		}
	}
	va_end(args);
	return (count);
}
