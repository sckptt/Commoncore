/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkinsfat <vkinsfat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 18:08:31 by vkinsfat          #+#    #+#             */
/*   Updated: 2025/02/04 15:52:03 by vkinsfat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

void uppercasify(char *str)
{
	int i = -1;

	while (str[++i])
	{
		str[i] = (char)std::toupper(str[i]);
		std::cout << str[i];
	}
}

int main(int ac, char **av)
{
	int i;

	i = 0;
	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else if (ac > 1)
	{
		while (av[++i])
			uppercasify(av[i]);
	}
	std::cout << "\n";
}
