/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkinsfat <vkinsfat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 14:59:05 by vkinsfat          #+#    #+#             */
/*   Updated: 2025/02/14 16:30:08 by vkinsfat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
	ClapTrap trap1("clapushka");
	ClapTrap trap2("trapushka");
	ScavTrap trap3("skavushka");
	
	trap3.guardGate();
	trap1.attack("skavushka");
	trap3.attack("trapushka");
	trap2.takeDamage(20);
	trap3.attack("clapushka");
	trap1.takeDamage(20);
}

