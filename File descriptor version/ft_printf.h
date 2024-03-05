/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitakinsfator <vitakinsfator@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 15:07:42 by vkinsfat          #+#    #+#             */
/*   Updated: 2024/03/05 17:30:59 by vitakinsfat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <stddef.h>

int		ft_printf(const char *str, ...);
void	ft_putchar_fd(char c, int fd);
void	ft_puthexl_fd(int n, int fd);
void	ft_puthexu_fd(int n, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putptr_fd(void *ptr, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putuns_fd(unsigned long n, int fd);
char	*ft_strchr(const char *str, int c);

#endif