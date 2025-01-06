/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitakinsfator <vitakinsfator@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 20:44:02 by vkinsfat          #+#    #+#             */
/*   Updated: 2025/01/06 14:55:02 by vitakinsfat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* Zombie::zombieHorde(int N, std::string name)
{
	Zombie* theHorde;

	if (N < 1)
		return NULL;
	theHorde = new Zombie[N];
	for (int i = 0; i < N; i++)
		theHorde[i].setName(name);
	return theHorde;
}