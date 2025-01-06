/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitakinsfator <vitakinsfator@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 20:39:19 by vkinsfat          #+#    #+#             */
/*   Updated: 2025/01/06 14:56:02 by vitakinsfat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

bool is_valid_number(std::string index)
{
	for (std::string::size_type i = 0; i < index.size(); i++)
	{
		if (!std::isdigit(index[i]))
			return false;
	}
	return true;
}

int main(int ac, char **av)
{
	Zombie* theHorde = NULL;
	int N;
	std::string name;

	if (ac != 3)
	{
		std::cout << "Please enter arguments: av[1] - number of zombies, av[2] - zombie name\n";
		return (1);
	}
	if (!is_valid_number(av[1]))
	{
		std::cout << "Non-numeric argument or negative number!\n";
		return (1);
	}
	N = atoi(av[1]);
	if (N == 0)
	{
		std::cout << "The number should be more than 0!\n";
		return (1);
	}
	name = av[2];
	theHorde = theHorde->zombieHorde(N, name);
	for (int i = 0; i < N; i++)
		theHorde[i].announce();
	delete[] theHorde;
}
