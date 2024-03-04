/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkinsfat <vkinsfat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 15:07:42 by vkinsfat          #+#    #+#             */
/*   Updated: 2024/03/04 18:02:04 by vkinsfat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>

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