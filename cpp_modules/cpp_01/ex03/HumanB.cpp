/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkinsfat <vkinsfat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 14:11:00 by vitakinsfat       #+#    #+#             */
/*   Updated: 2025/02/10 13:37:26 by vkinsfat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

void HumanB::attack()
{
	if (_weaponB)
		std::cout << _nameB << " attacks with their " << _weaponB->getType() << std::endl;
	else
		std::cout << _nameB << " has no weapon to attack" << std::endl;
}

void HumanB::setWeapon(Weapon& weapon)
{
	this->_weaponB = &weapon;
}

HumanB::HumanB(const std::string& name)
{
	_nameB = name;
	_weaponB = NULL;
}