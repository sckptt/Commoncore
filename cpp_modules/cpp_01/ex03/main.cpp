/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitakinsfator <vitakinsfator@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 14:02:23 by vitakinsfat       #+#    #+#             */
/*   Updated: 2025/01/06 19:56:38 by vitakinsfat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "HumanB.hpp"

int main(void)
{
	// Weapon baseballBat("baseball bat with nails");
	// Weapon knife("old rusty knife");
	// HumanA alice("Alice", baseballBat);
	// HumanB bob("Bob");
	
	// bob.setWeaponB(&knife);
	// alice.attack();
	// bob.attack();

    Weapon  club = Weapon("crude spiked club");
    HumanA bob("Bob", club);
    bob.attack();
    club.setType("some other type of club");
    bob.attack();

	Weapon  club1 = Weapon("crude spiked club");
	HumanB jim("Jim");
	jim.setWeapon(&club1);
	jim.attack();
	club1.setType("some other type of club");
	jim.attack();

	return 0;
}