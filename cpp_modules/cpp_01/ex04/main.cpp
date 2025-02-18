/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkinsfat <vkinsfat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 20:31:04 by vitakinsfat       #+#    #+#             */
/*   Updated: 2025/02/10 13:52:26 by vkinsfat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SedIsForLosers.hpp"

int main(int ac, char **av)
{

	if (ac != 4)
	{
		std::cout << "This program requires 3 arguments!" << std::endl;
		return (1);
	}
	try
	{
		SedIsForLosers SedIsForLosers(av);
		SedIsForLosers.readFile();
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return (1);
	}
	return (0);
}
