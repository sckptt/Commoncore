/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkinsfat <vkinsfat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 19:13:48 by vkinsfat          #+#    #+#             */
/*   Updated: 2024/12/20 19:14:37 by vkinsfat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>

class Contact
{
	private:
		std::string FirstName;
		std::string LastName;
		std::string Nickname;
		std::string PhoneNumber;
		std::string DarkestSecret;

	public:
		std::string GetFirstName() const;
		std::string GetLastName() const;
		std::string GetNickname() const;
		std::string GetPhoneNumber() const;
		std::string GetDarkestSecret() const;
		void SetFirstName(std::string first_name);
		void SetLastName(std::string last_name);
		void SetNickname(std::string nickname);
		void SetPhoneNumber(std::string phone_number);
		void SetDarkestSecret(std::string darkest_secret);
};

#endif