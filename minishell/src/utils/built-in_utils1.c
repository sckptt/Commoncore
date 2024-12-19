/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built-in_utils1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitakinsfator <vitakinsfator@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 15:37:40 by vitakinsfat       #+#    #+#             */
/*   Updated: 2024/10/15 15:31:50 by vitakinsfat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_valid_digit(char *str)
{
	int	i;

	i = 0;
	if (!str || str[0] == '\0')
		return (FALSE);
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i])
	{
		if (ft_isdigit(str[i]) == FALSE)
			return (FALSE);
		i++;
	}
	return (TRUE);
}

long long	ft_atoll(char *str)
{
	int			i;
	long long	one;
	long long	result;

	i = 0;
	one = 1;
	result = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == 45 || str[i] == 43)
	{
		if (str[i] == 45)
			one = -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * one);
}

int	ft_strcmp(char *first_str, char *second_str)
{
	int	i;

	i = 0;
	if (!first_str && !second_str)
		return (0);
	while (first_str[i] != '\0' && second_str[i] != '\0')
	{
		if (first_str[i] != second_str[i])
			return (first_str[i] - second_str[i]);
		i++;
	}
	return (first_str[i] - second_str[i]);
}
