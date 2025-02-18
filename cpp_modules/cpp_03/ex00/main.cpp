/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkinsfat <vkinsfat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 14:59:05 by vkinsfat          #+#    #+#             */
/*   Updated: 2025/02/14 15:40:53 by vkinsfat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap trap1("clapushka");
	ClapTrap trap2("trapushka");
	ClapTrap trap3(trap1);
	ClapTrap trap4;

	trap1.attack("trapushka");
	trap2.takeDamage(10);
	trap4 = trap2;
	trap2.attack("clapushka");
	trap3.beRepaired(10);
	trap4.beRepaired(2);
}

