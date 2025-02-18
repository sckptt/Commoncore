/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkinsfat <vkinsfat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 18:44:13 by vkinsfat          #+#    #+#             */
/*   Updated: 2025/02/14 14:51:17 by vkinsfat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// Constructors
Fixed::Fixed()
{
	this->_value = 0;
}

Fixed::Fixed(const int value)
{
	this->_value = value << _fractBits;
}

Fixed::Fixed(const float value)
{
	this->_value = roundf(value * (1 << _fractBits));
}

Fixed::Fixed(const Fixed& obj)
{
	this->_value = obj.getRawBits();
}

Fixed&	Fixed::operator=(const Fixed& obj)
{
	if (this != &obj)
		this->_value = obj.getRawBits();
	return *this;
}

Fixed::~Fixed()
{
}

// Getter/setter
int	Fixed::getRawBits(void) const
{
	return this->_value;
}

void	Fixed::setRawBits(int const raw)
{
	this->_value = raw;
}

// Conversions
float	Fixed::toFloat(void) const
{
	return ((float)this->_value / (float)((1 << _fractBits)));
}

int	Fixed::toInt(void) const
{
	return (this->_value >> _fractBits);
}

// Comparisons
bool Fixed::operator>(const Fixed& obj) const
{
	return (this->_value > obj.getRawBits());
}

bool Fixed::operator<(const Fixed& obj) const
{
	return (this->_value < obj.getRawBits());
}

bool Fixed::operator>=(const Fixed& obj) const
{
	return (this->_value >= obj.getRawBits());
}

bool Fixed::operator<=(const Fixed& obj) const
{
	return (this->_value <= obj.getRawBits());
}

bool Fixed::operator==(const Fixed& obj) const
{
	return (this->_value == obj.getRawBits());
}

bool Fixed::operator!=(const Fixed& obj) const
{
	return (this->_value != obj.getRawBits());
}

// Arithmetic
Fixed Fixed::operator+(const Fixed& obj)
{
	return Fixed(this->toFloat() + obj.toFloat());
}

Fixed Fixed::operator-(const Fixed& obj)
{
	return Fixed(this->toFloat() - obj.toFloat());
}

Fixed Fixed::operator*(const Fixed& obj)
{
	return Fixed(this->toFloat() * obj.toFloat());
}

Fixed Fixed::operator/(const Fixed& obj)
{
	return Fixed(this->toFloat() /obj.toFloat());
}

// Increment/decrement
Fixed& Fixed::operator++(void)
{
	this->_value++;
	return *this;	
}

Fixed Fixed::operator++(int)
{
	Fixed temp = *this;
	
    ++(*this);
	return temp;
}

Fixed& Fixed::operator--(void)
{
	this->_value--;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed temp = *this;
	
    --(*this);
	return temp;
}

// Min/max
Fixed& Fixed::min(Fixed& obj1, Fixed& obj2)
{
	if (obj1 < obj2)
		return obj1;
	return obj2;
}

const Fixed& Fixed::min(const Fixed& obj1, const Fixed& obj2)
{
	if (obj1 < obj2)
		return obj1;
	return obj2;
}

Fixed& Fixed::max(Fixed& obj1, Fixed& obj2)
{
	if (obj1 > obj2)
		return obj1;
	return obj2;
}

const Fixed& Fixed::max(const Fixed& obj1, const Fixed& obj2)
{
	if (obj1 > obj2)
		return obj1;
	return obj2;
}
		