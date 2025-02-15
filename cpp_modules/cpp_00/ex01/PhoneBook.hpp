/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitakinsfator <vitakinsfator@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 19:14:01 by vkinsfat          #+#    #+#             */
/*   Updated: 2025/01/06 14:49:56 by vitakinsfat      ###   ########.fr       */
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
		Contact myContacts[8];
		int	numberOfContacts;
	
	void addContact(const std::string (&info)[5], int index);
	void searchContact() const;
	void showContact(int index) const;
};

#endif