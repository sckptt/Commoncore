/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkinsfat <vkinsfat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 20:39:19 by vkinsfat          #+#    #+#             */
/*   Updated: 2024/12/27 21:04:23 by vkinsfat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	Zombie* TheHorde = NULL;
	TheHorde = TheHorde->zombieHorde(8, "Valter");
	for (int i = 0; i < 8; i++)
	{
		TheHorde[i].Announce();
	}
	delete[] TheHorde;
}