/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkinsfat <vkinsfat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 20:39:19 by vkinsfat          #+#    #+#             */
/*   Updated: 2025/02/10 13:26:45 by vkinsfat         ###   ########.fr       */
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
		std::cout << "Please enter arguments: av[1] - number of zombies, av[2] - zombie name" << std::endl;
		return (1);
	}
	if (!is_valid_number(av[1]))
	{
		std::cout << "Non-numeric argument or negative number!" << std::endl;
		return (1);
	}
	N = atoi(av[1]);
	if (N == 0)
	{
		std::cout << "The number should be more than 0!" << std::endl;
		return (1);
	}
	name = av[2];
	theHorde = theHorde->zombieHorde(N, name);
	for (int i = 0; i < N; i++)
		theHorde[i].announce();
	delete[] theHorde;
}
