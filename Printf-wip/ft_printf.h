/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkinsfat <vkinsfat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 15:07:42 by vkinsfat          #+#    #+#             */
/*   Updated: 2024/03/05 16:39:42 by vkinsfat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <stddef.h>
# include <limits.h>

int		ft_printf(const char *str, ...);
void	ft_putchar(char c, int *count);
void	ft_puthexl(int n, int *count);
void	ft_puthexu(int n, int *count);
void	ft_putnbr(int n, int *count);
void	ft_putptr(void *ptr, int *count);
void	ft_putstr(char *s, int *count);
void	ft_putuns(unsigned int n, int *count);
char	*ft_strchr(const char *str, int c);
size_t	ft_strlen(const char *str);

#endif