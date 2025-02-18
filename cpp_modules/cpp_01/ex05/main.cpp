/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkinsfat <vkinsfat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 14:29:01 by vitakinsfat       #+#    #+#             */
/*   Updated: 2025/02/10 13:30:55 by vkinsfat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "This program requires only one argument!" << std::endl;
		return 1;
	}
	Harl harl;
	harl.complain(av[1]);
	return 0;
}
