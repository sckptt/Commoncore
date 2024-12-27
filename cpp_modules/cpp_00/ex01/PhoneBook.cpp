/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkinsfat <vkinsfat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 19:56:11 by vkinsfat          #+#    #+#             */
/*   Updated: 2024/12/27 18:22:16 by vkinsfat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void PhoneBook::AddContact(const std::string (&info)[5], int index)
{
	MyContacts[index].SetFirstName(info[0]);
	MyContacts[index].SetLastName(info[1]);
	MyContacts[index].SetNickname(info[2]);
	MyContacts[index].SetPhoneNumber(info[3]);
	MyContacts[index].SetDarkestSecret(info[4]);
}

void PhoneBook::ShowContact(int index) const
{
	std::cout << "First name is ";
	std::cout << MyContacts[index].GetFirstName() << "\n" << std::endl;
	std::cout << "Last name is ";
	std::cout << MyContacts[index].GetLastName() << "\n" << std::endl;
	std::cout << "Nickname is ";
	std::cout << MyContacts[index].GetNickname() << "\n" << std::endl;
	std::cout << "Phone number is ";
	std::cout << MyContacts[index].GetPhoneNumber() << "\n" << std::endl;
	std::cout << "The darkest secret is ";
	std::cout << MyContacts[index].GetDarkestSecret() << "\n" << std::endl;
}

void print_header(void)
{
	std::cout << "+----------+----------+----------+----------+\n";
	std::cout << "|     index|first name| last name|  nickname|\n";
	std::cout << "+----------+----------+----------+----------+\n";
}

void print_info(int i, const Contact MyContacts[])
{
	std::string first_name = MyContacts[i].GetFirstName();
	std::string last_name = MyContacts[i].GetLastName();
	std::string nickname = MyContacts[i].GetNickname();
	
	if (first_name.length() > 10)
		first_name = first_name.substr(0, 9) + ".";
	if (last_name.length() > 10)
		last_name = last_name.substr(0, 9) + ".";
	if (nickname.length() > 10)
		nickname = nickname.substr(0, 9) + ".";
	std::cout << "|";
	std::cout << std::setw(10) << std::right << i;
	std::cout << "|";
	std::cout << std::setw(10) << std::right << first_name;
	std::cout << "|";
	std::cout << std::setw(10) << std::right << last_name;
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

void PhoneBook::SearchContact(void) const
{
	int i = 0;
	std::string chosen_index;
	int res_index;
	
	print_header();
	while (i < number_of_contacts)
	{
		print_info(i, MyContacts);
		i++;
	}
	while (1)
	{
		if (number_of_contacts == 0)
			break;
		std::cout << "Choose your index: " << std::endl;
		std::getline(std::cin, chosen_index);
		if (!is_valid_number(chosen_index))
			continue ;
		res_index = std::atoi(chosen_index.c_str());
		if (res_index < 0 || res_index > (number_of_contacts - 1))
			continue ;
		else
			break;
	}
	ShowContact(res_index);
}
