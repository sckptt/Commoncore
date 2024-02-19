/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkinsfat <vkinsfat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 13:15:13 by vkinsfat          #+#    #+#             */
/*   Updated: 2024/02/19 13:15:16 by vkinsfat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = n * -1;
	}
	if (n >= 10)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
	else
	{
		ft_putchar_fd(n + '0', fd);
	}
}

/*int main(void)
{
	int num1;
	int num2;

	num1 = 12345;

	num2 = -2147483648;
	ft_putnbr_fd(num2, 1);
	printf("%c", '\n');
	ft_putnbr_fd(-785748934, 1);
	printf("%c", '\n');
	ft_putnbr_fd(num1, 1);
	printf("%c", '\n');
	return (0);
}*/
