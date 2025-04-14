/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitakinsfator <vitakinsfator@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 21:36:24 by vitakinsfat       #+#    #+#             */
/*   Updated: 2025/04/14 22:15:02 by vitakinsfat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Dog.hpp"

Dog::Dog()
{
	std::cout << "Dog constructor called" << std::endl;
	this->_type = "Dog";
}
Dog::Dog(const Dog& obj)
{
	std::cout << "Dog copy constructor called" << std::endl;
	this->_type = obj._type;
}

Dog& Dog::operator=(const Dog& obj)
{
	std::cout << "Dog copy assignment operator called" << std::endl;
	if (this != &obj)
	{
		this->_type = obj._type;
	}
	return (*this);
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound(void) const
{
	std::cout <<"*Woof woof*" << std::endl;
}