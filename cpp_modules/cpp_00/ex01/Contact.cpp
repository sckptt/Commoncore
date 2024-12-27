/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkinsfat <vkinsfat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 19:13:31 by vkinsfat          #+#    #+#             */
/*   Updated: 2024/12/26 18:20:58 by vkinsfat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

const std::string& Contact::GetFirstName(void) const
{
	return _first_name;
}

const std::string& Contact::GetLastName(void) const
{
	return _last_name;
}

const std::string& Contact::GetNickname(void) const
{
	return _nickname;
}

const std::string& Contact::GetPhoneNumber(void) const
{
	return _phone_number;
}

const std::string& Contact::GetDarkestSecret(void) const
{
	return _darkest_secret;
}

void Contact::SetFirstName(const std::string& first_name)
{
	this->_first_name = first_name;
}

void Contact::SetLastName(const std::string& last_name)
{
	this->_last_name = last_name;
}

void Contact::SetNickname(const std::string& nickname)
{
	this->_nickname = nickname;
}

void Contact::SetPhoneNumber(const std::string& phone_number)
{
	this->_phone_number = phone_number;
}

void Contact::SetDarkestSecret(const std::string& darkest_secret)
{
	this->_darkest_secret = darkest_secret;
}
