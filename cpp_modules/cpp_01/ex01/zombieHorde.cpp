/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkinsfat <vkinsfat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 20:44:02 by vkinsfat          #+#    #+#             */
/*   Updated: 2024/12/27 20:57:34 by vkinsfat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* Zombie::zombieHorde(int N, std::string name)
{
	Zombie* TheHorde;

	if (N < 1)
		return NULL;
	TheHorde = new Zombie[N];
	for (int i = 0; i < N; i++)
	{
		TheHorde[i].SetName(name);
	}
	return TheHorde;
}