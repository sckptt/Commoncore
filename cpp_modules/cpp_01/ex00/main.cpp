/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitakinsfator <vitakinsfator@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 18:09:05 by vkinsfat          #+#    #+#             */
/*   Updated: 2025/01/06 14:53:56 by vitakinsfat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	Zombie *HZombie;
	HZombie = Zombie::newZombie("Hugh");
	HZombie->announce();
	delete HZombie;

	Zombie::randomChump("Lil George");
	return (0);
}
