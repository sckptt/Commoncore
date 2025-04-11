/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitakinsfator <vitakinsfator@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 18:12:52 by vitakinsfat       #+#    #+#             */
/*   Updated: 2025/04/07 18:40:26 by vitakinsfat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("No_name")
{
	std::cout << "DiamondTrap default constructor called" << std::endl;
	this->_name = "Default name";
	this->_hitPoints = FragTrap::_hitPoints;
	this->_energyPoints = ScavTrap::_energyPoints;
	this->_attackDamage = FragTrap::_attackDamage;
}

DiamondTrap::DiamondTrap(const std::string& name) : ClapTrap(name + "_clap_name")
{
	std::cout << "DiamondTrap default constructor called" << std::endl;
	this->_name = name;
	this->_hitPoints = FragTrap::_hitPoints;
	this->_energyPoints = ScavTrap::_energyPoints;
	this->_attackDamage = FragTrap::_attackDamage;
}

// DiamondTrap::DiamondTrap(const DiamondTrap& obj)
// {
// 	std::cout << "DiamondTrap copy constructor called" << std::endl;
// 	this->_name = obj._name;
// 	this->_hitPoints = obj._hitPoints;
// 	this->_energyPoints = obj._energyPoints;
// 	this->_attackDamage = obj._attackDamage;
// }

// DiamondTrap& DiamondTrap::operator=(const DiamondTrap& obj)
// {
// 	std::cout << "DiamondTrap copy assignment operator called" << std::endl;
// 	if (this != &obj)
// 	{
// 		this->_name = obj._name;
// 		this->_hitPoints = obj._hitPoints;
// 		this->_energyPoints = obj._energyPoints;
// 		this->_attackDamage = obj._attackDamage;
// 	}
// 	return *this;
// }

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap destructor called" << std::endl;
}

void DiamondTrap::whoAmI(void)
{
	std::cout << "My name is " << this->_name << " , my ClapTrap name is " << ClapTrap::_name << std::endl;
}