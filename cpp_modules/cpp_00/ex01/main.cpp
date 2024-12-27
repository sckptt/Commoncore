/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkinsfat <vkinsfat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 19:12:58 by vkinsfat          #+#    #+#             */
/*   Updated: 2024/12/27 18:23:42 by vkinsfat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void add_contact(PhoneBook& my_phonebook, int index)
{
	std::string info[5];

	std::cout << "First name is " << std::endl;
	std::getline(std::cin, info[0]);
	std::cout << "Last name is " << std::endl;
	std::getline(std::cin, info[1]);
	std::cout << "Nickname is " << std::endl;
	std::getline(std::cin, info[2]);
	std::cout << "Phone number is " << std::endl;
	std::getline(std::cin, info[3]);
	std::cout << "Darkest secret is " << std::endl;
	std::getline(std::cin, info[4]);
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
		std::cout << ">" << std::endl;
		std::getline(std::cin, input);
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
			std::cout << "This command is invalid!\n" << std::endl;
			continue ;
		}
	}
}
