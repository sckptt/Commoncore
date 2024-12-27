/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkinsfat <vkinsfat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 18:09:05 by vkinsfat          #+#    #+#             */
/*   Updated: 2024/12/27 20:34:08 by vkinsfat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	Zombie *HZombie;
	HZombie = Zombie::newZombie("Hugh");
	HZombie->Announce();
	delete HZombie;

	Zombie::randomChump("Lil George");
	return (0);
}
