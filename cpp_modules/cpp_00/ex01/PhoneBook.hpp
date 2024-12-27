/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkinsfat <vkinsfat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 19:14:01 by vkinsfat          #+#    #+#             */
/*   Updated: 2024/12/26 17:19:25 by vkinsfat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONE_BOOK_HPP
# define PHONE_BOOK_HPP

# include <iostream>
# include <iomanip>
# include <unistd.h>
# include <cstdlib>
# include <cctype>
# include "Contact.hpp"

class PhoneBook
{
	public:
		Contact MyContacts[8];
		int	number_of_contacts;
	
	void AddContact(const std::string (&info)[5], int index);
	void SearchContact() const;
	void ShowContact(int index) const;
};

#endif