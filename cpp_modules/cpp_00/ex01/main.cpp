/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitakinsfator <vitakinsfator@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 19:12:58 by vkinsfat          #+#    #+#             */
/*   Updated: 2025/01/05 15:01:18 by vitakinsfat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void add_contact(PhoneBook& my_phonebook, int index)
{
	std::string info[5];

	while (info[0].empty())
	{
		std::cout << "First name is ";
		if (!std::getline(std::cin, info[0]))
			return ;
	}
	while (info[1].empty())
	{
		std::cout << "Last name is ";
		if (!std::getline(std::cin, info[1]))
			return ;
	}
	while (info[2].empty())
	{
		std::cout << "Nickname is ";
		if (!std::getline(std::cin, info[2]))
			return ;
	}
	while (info[3].empty())
	{
		std::cout << "Phone number is ";
		if (!std::getline(std::cin, info[3]))
			return ;
	}
	while (info[4].empty())
	{
		std::cout << "Darkest secret is ";
		if (!std::getline(std::cin, info[4]))
			return ;
	}
	my_phonebook.AddContact(info, index);
}

int main()
{
	std::string input;
	PhoneBook my_phonebook;
	int index = 0;
	
	my_phonebook.number_of_contacts = 0;
	while (1)
	{
		std::cout << ">";
		if (!std::getline(std::cin, input))
		{
			std::cout << "EOF detected. Good bye!" << std::endl;
			break ;
		}
		if (input == "ADD")
		{
			add_contact(my_phonebook, index);
			index = (index + 1) % 8;
			if (my_phonebook.number_of_contacts < 8)
				my_phonebook.number_of_contacts++;
		}
		else if (input == "SEARCH")
			my_phonebook.SearchContact();
		else if (input == "EXIT")
			break ;
		else
		{
			std::cout << "This command is invalid!\n";
			continue ;
		}
	}
}
