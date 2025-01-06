/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitakinsfator <vitakinsfator@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 19:13:31 by vkinsfat          #+#    #+#             */
/*   Updated: 2025/01/06 14:45:27 by vitakinsfat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

const std::string& Contact::getFirstName(void) const
{
	return _firstName;
}

const std::string& Contact::getLastName(void) const
{
	return _lastName;
}

const std::string& Contact::getNickname(void) const
{
	return _nickname;
}

const std::string& Contact::getPhoneNumber(void) const
{
	return _phoneNumber;
}

const std::string& Contact::getDarkestSecret(void) const
{
	return _darkestSecret;
}

void Contact::setFirstName(const std::string& firstName)
{
	this->_firstName = firstName;
}

void Contact::setLastName(const std::string& lastName)
{
	this->_lastName = lastName;
}

void Contact::setNickname(const std::string& nickname)
{
	this->_nickname = nickname;
}

void Contact::setPhoneNumber(const std::string& phoneNumber)
{
	this->_phoneNumber = phoneNumber;
}

void Contact::setDarkestSecret(const std::string& darkestSecret)
{
	this->_darkestSecret = darkestSecret;
}
