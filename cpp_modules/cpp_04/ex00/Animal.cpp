/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitakinsfator <vitakinsfator@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 21:02:00 by vitakinsfat       #+#    #+#             */
/*   Updated: 2025/04/14 22:14:22 by vitakinsfat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "Animal constructor called" << std::endl;
	this->_type = "Default_type";
}

Animal::Animal(const Animal& obj)
{
	std::cout << "Animal copy constructor called" << std::endl;
	this->_type = obj._type;
}

Animal& Animal::operator=(const Animal& obj)
{
	std::cout << "Animal copy asignment operator called" << std::endl;
	if (this != &obj)
	{
		this->_type = obj._type;
	}
	return (*this);
}

Animal::~Animal()
{
	std::cout << "Animal destructor called" << std::endl;
}

const std::string& Animal::getType(void) const
{
	return (this->_type);
}

void Animal::makeSound(void) const
{
	std::cout << "*Default animal sound*" << std::endl;
}
