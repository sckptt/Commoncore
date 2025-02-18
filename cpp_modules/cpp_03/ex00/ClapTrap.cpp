/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkinsfat <vkinsfat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 14:59:48 by vkinsfat          #+#    #+#             */
/*   Updated: 2025/02/14 16:19:44 by vkinsfat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	std::cout << "Default constructor called" << std::endl;
	this->_name = "No_name";
	this->_hitPoints = 10;
	this->_energyPoints = 10;
	this->_attackDamage = 0;
}

ClapTrap::ClapTrap(const std::string& name)
{
	std::cout << "Default constructor called" << std::endl;
	this->_name = name;
	this->_hitPoints = 10;
	this->_energyPoints = 10;
	this->_attackDamage = 0;
}

ClapTrap::ClapTrap(const ClapTrap& obj)
{
	std::cout << "Copy constructor called" << std::endl;
	this->_name = obj._name;
	this->_hitPoints = obj._hitPoints;
	this->_energyPoints = obj._energyPoints;
	this->_attackDamage = obj._attackDamage;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& obj)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &obj)
	{
		this->_name = obj._name;
		this->_hitPoints = obj._hitPoints;
		this->_energyPoints = obj._energyPoints;
		this->_attackDamage = obj._attackDamage;
	}
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	if (_hitPoints == 0 || _energyPoints == 0)
		return;
	_energyPoints--;
	std::cout << "ClapTrap " << _name << " attacks ";
	std::cout << target << ", causing ";
	std::cout << _attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (_hitPoints == 0)
		return;
	_hitPoints -= amount;
	std::cout << "ClapTrap " << _name << " takes ";
	std::cout << amount << " points of damage!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_hitPoints == 0 || _energyPoints == 0)
		return;
	_hitPoints += amount;
	_energyPoints--;
	std::cout << "ClapTrap " << _name << " restores ";
	std::cout << amount << " hit points!" << std::endl;
}
