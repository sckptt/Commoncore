/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitakinsfator <vitakinsfator@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 14:59:05 by vkinsfat          #+#    #+#             */
/*   Updated: 2025/04/14 20:48:04 by vitakinsfat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main(void)
{
	ClapTrap trap1("clapushka");
	ScavTrap trap2("skavushka");
	FragTrap trap3("fragushka");
	DiamondTrap trap4("diamondushka");
	DiamondTrap trap5(trap4);
	
	trap2.guardGate();
	trap1.attack("skavushka");
	trap2.takeDamage(0);
	trap2.attack("clapushka");
	trap1.takeDamage(20);
	trap3.highFivesGuys();
	trap3.attack("skavushka");
	trap2.takeDamage(30);
	trap4.whoAmI();
	trap5.whoAmI();
}

