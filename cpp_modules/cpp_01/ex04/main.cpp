/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitakinsfator <vitakinsfator@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 20:31:04 by vitakinsfat       #+#    #+#             */
/*   Updated: 2025/01/07 14:02:44 by vitakinsfat      ###   ########.fr       */
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
		SedIsForLosers sifl(av);
		sifl.readFile();
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return (1);
	}
	return (0);
}
