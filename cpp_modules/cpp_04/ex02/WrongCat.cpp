/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitakinsfator <vitakinsfator@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 22:21:14 by vitakinsfat       #+#    #+#             */
/*   Updated: 2025/04/14 22:28:08 by vitakinsfat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	std::cout << "WrongCat constructor called" << std::endl;
	this->_type = "That isn't a cat... I don't know what IS that";
}

WrongCat::WrongCat(const WrongCat& obj)
{
	std::cout << "WrongCat copy constructor called" << std::endl;
	this->_type = obj._type;
}
WrongCat& WrongCat::operator=(const WrongCat& obj)
{
	std::cout << "WrongCat copy assignment operator called" << std::endl;
	if (this != &obj)
	{
		this->_type = obj._type;
	}
	return (*this);
}

WrongCat::~WrongCat()
{
	std::cout << "Curiosity killed it... You should be happy about it" << std::endl;
}

void WrongCat::makeSound(void) const
{
	std::cout <<"*Meow meow*" << std::endl;
}
