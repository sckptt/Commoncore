/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkinsfat <vkinsfat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 19:56:11 by vkinsfat          #+#    #+#             */
/*   Updated: 2025/02/04 16:12:33 by vkinsfat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void	PhoneBook::addContact(const std::string (&info)[5], int index)
{
	_myContacts[index].setFirstName(info[0]);
	_myContacts[index].setLastName(info[1]);
	_myContacts[index].setNickname(info[2]);
	_myContacts[index].setPhoneNumber(info[3]);
	_myContacts[index].setDarkestSecret(info[4]);
}

void	PhoneBook::showContact(int index) const
{
	std::cout << "First name is ";
	std::cout << _myContacts[index].getFirstName() << std::endl;
	std::cout << "Last name is ";
	std::cout << _myContacts[index].getLastName() << std::endl;
	std::cout << "Nickname is ";
	std::cout << _myContacts[index].getNickname() << std::endl;
	std::cout << "Phone number is ";
	std::cout << _myContacts[index].getPhoneNumber() << std::endl;
	std::cout << "The darkest secret is ";
	std::cout << _myContacts[index].getDarkestSecret() << std::endl;
}

void	print_header(void)
{
	std::cout << "+----------+----------+----------+----------+" << std::endl;
	std::cout << "|     index|first name| last name|  nickname|" << std::endl;
	std::cout << "+----------+----------+----------+----------+" << std::endl;
}

void	print_info(int i, const Contact myContacts[])
{
	std::string firstName = myContacts[i].getFirstName();
	std::string lastName = myContacts[i].getLastName();
	std::string nickname = myContacts[i].getNickname();
	
	if (firstName.length() > 10)
		firstName = firstName.substr(0, 9) + ".";
	if (lastName.length() > 10)
		lastName = lastName.substr(0, 9) + ".";
	if (nickname.length() > 10)
		nickname = nickname.substr(0, 9) + ".";
	std::cout << "|";
	std::cout << std::setw(10) << std::right << i;
	std::cout << "|";
	std::cout << std::setw(10) << std::right << firstName;
	std::cout << "|";
	std::cout << std::setw(10) << std::right << lastName;
	std::cout << "|";
	std::cout << std::setw(10) << std::right << nickname;
	std::cout << "|" << std::endl;
	std::cout << "+----------+----------+----------+----------+" << std::endl;
}

bool	is_valid_number(std::string index)
{
	for (std::string::size_type i = 0; i < index.size(); i++)
	{
		if (!std::isdigit(index[i]))
			return false;
	}
	return true;
}

void	PhoneBook::searchContact(void) const
{
	std::string	chosenIndex;
	int			i = 0;
	int			resIndex;

	if (_numberOfContacts == 0)
	{
		std::cout << "No contacts in the phone book!" << std::endl;
		return ;
	}
	print_header();
	while (i < _numberOfContacts)
	{
		print_info(i, _myContacts);
		i++;
	}
	while (1)
	{
		std::cout << "Choose your index: " << std::endl;
		if (!std::getline(std::cin, chosenIndex))
			return ;
		if (chosenIndex.empty())
			continue ;
		if (!is_valid_number(chosenIndex))
			continue ;
		resIndex = std::atoi(chosenIndex.c_str());
		if (resIndex < 0 || resIndex > (_numberOfContacts - 1))
			continue ;
		else
			break;
	}
	showContact(resIndex);
}

int	PhoneBook::getNumberOfContacts(void) const
{
	return _numberOfContacts;
}

void	PhoneBook::setNumberOfContacts(int numberOfContacts)
{
	this->_numberOfContacts = numberOfContacts;
}
