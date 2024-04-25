/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitakinsfator <vitakinsfator@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 16:45:12 by vkinsfat          #+#    #+#             */
/*   Updated: 2024/04/23 19:38:37 by vitakinsfat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	handle_format(va_list args, char format, int *count)
{
	void	*ptr;

	if (format == 'c')
		ft_putchar(va_arg(args, int), count);
	else if (format == 's')
		ft_putstr(va_arg(args, char *), count);
	else if (format == 'p')
	{
		ptr = va_arg(args, void *);
		if (ptr)
			ft_putptr(ptr, count);
		else
			ft_putstr("(nil)", count);
	}
	else if (format == 'd' || format == 'i')
		ft_putnbr(va_arg(args, int), count);
	else if (format == 'u')
		ft_putuns(va_arg(args, unsigned int), count);
	else if (format == 'x')
		ft_puthexl(va_arg(args, int), count);
	else if (format == 'X')
		ft_puthexu(va_arg(args, int), count);
	else if (format == '%')
		ft_putchar('%', count);
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
			handle_format(args, str[i + 1], &count);
			i += 2;
		}
		else
		{
			ft_putchar(str[i], &count);
			i++;
		}
	}
	va_end(args);
	return (count);
}
