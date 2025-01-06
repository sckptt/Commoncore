/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitakinsfator <vitakinsfator@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 19:56:11 by vkinsfat          #+#    #+#             */
/*   Updated: 2025/01/06 14:50:43 by vitakinsfat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void PhoneBook::addContact(const std::string (&info)[5], int index)
{
	myContacts[index].setFirstName(info[0]);
	myContacts[index].setLastName(info[1]);
	myContacts[index].setNickname(info[2]);
	myContacts[index].setPhoneNumber(info[3]);
	myContacts[index].setDarkestSecret(info[4]);
}

void PhoneBook::showContact(int index) const
{
	std::cout << "First name is ";
	std::cout << myContacts[index].getFirstName() << "\n";
	std::cout << "Last name is ";
	std::cout << myContacts[index].getLastName() << "\n";
	std::cout << "Nickname is ";
	std::cout << myContacts[index].getNickname() << "\n";
	std::cout << "Phone number is ";
	std::cout << myContacts[index].getPhoneNumber() << "\n";
	std::cout << "The darkest secret is ";
	std::cout << myContacts[index].getDarkestSecret() << "\n";
}

void print_header(void)
{
	std::cout << "+----------+----------+----------+----------+\n";
	std::cout << "|     index|first name| last name|  nickname|\n";
	std::cout << "+----------+----------+----------+----------+\n";
}

void print_info(int i, const Contact myContacts[])
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
	std::cout << "|\n";
	std::cout << "+----------+----------+----------+----------+\n";
}

bool is_valid_number(std::string index)
{
	for (std::string::size_type i = 0; i < index.size(); i++)
	{
		if (!std::isdigit(index[i]))
			return false;
	}
	return true;
}

void PhoneBook::searchContact(void) const
{
	int i = 0;
	std::string chosenIndex;
	int resIndex;
	
	if (numberOfContacts == 0)
	{
		std::cout << "No contacts in the phone book!\n";
		return ;
	}
	print_header();
	while (i < numberOfContacts)
	{
		print_info(i, myContacts);
		i++;
	}
	while (1)
	{
		std::cout << "Choose your index: ";
		if (!std::getline(std::cin, chosenIndex))
			return ;
		if (!is_valid_number(chosenIndex))
			continue ;
		resIndex = std::atoi(chosenIndex.c_str());
		if (resIndex < 0 || resIndex > (numberOfContacts - 1))
			continue ;
		else
			break;
	}
	showContact(resIndex);
}
