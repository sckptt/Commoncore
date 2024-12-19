/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitakinsfator <vitakinsfator@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 16:14:32 by vitakinsfat       #+#    #+#             */
/*   Updated: 2024/10/28 16:28:53 by vitakinsfat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_pwd(void)
{
	char	current_wd[1024];

	if (getcwd(current_wd, 1024) != NULL)
	{
		printf("%s\n", current_wd);
		return (SUCCESS);
	}
	else
	{
		perror("minishell: pwd");
		return (FAILURE);
	}
}
