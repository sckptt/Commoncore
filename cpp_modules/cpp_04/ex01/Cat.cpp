/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitakinsfator <vitakinsfator@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 21:17:58 by vitakinsfat       #+#    #+#             */
/*   Updated: 2025/04/14 22:14:40 by vitakinsfat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "Cat constructor called" << std::endl;
	this->_type = "Cat";
}

Cat::Cat(const Cat& obj)
{
	std::cout << "Cat copy constructor called" << std::endl;
	this->_type = obj._type;
}
Cat& Cat::operator=(const Cat& obj)
{
	std::cout << "Cat copy assignment operator called" << std::endl;
	if (this != &obj)
	{
		this->_type = obj._type;
	}
	return (*this);
}

Cat::~Cat()
{
	std::cout << "Curiosity killed the cat!" << std::endl;
}

void Cat::makeSound(void) const
{
	std::cout <<"*Meow meow*" << std::endl;
}