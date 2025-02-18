/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkinsfat <vkinsfat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 19:14:01 by vkinsfat          #+#    #+#             */
/*   Updated: 2025/02/04 16:11:34 by vkinsfat         ###   ########.fr       */
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
	private:
		Contact _myContacts[8];
		int		_numberOfContacts;
	
	public:
	int		getNumberOfContacts(void) const;
	void	addContact(const std::string (&info)[5], int index);
	void	searchContact() const;
	void	showContact(int index) const;
	void	setNumberOfContacts(int numberOfContacts);
};

#endif