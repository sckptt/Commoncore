/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkinsfat <vkinsfat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 19:13:48 by vkinsfat          #+#    #+#             */
/*   Updated: 2024/12/26 18:20:35 by vkinsfat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>

class Contact
{
	private:
		std::string _first_name;
		std::string _last_name;
		std::string _nickname;
		std::string _phone_number;
		std::string _darkest_secret;

	public:
		const std::string &GetFirstName(void) const;
		const std::string &GetLastName(void) const;
		const std::string &GetNickname(void) const;
		const std::string &GetPhoneNumber(void) const;
		const std::string &GetDarkestSecret(void) const;
		void SetFirstName(const std::string& first_name);
		void SetLastName(const std::string& last_name);
		void SetNickname(const std::string& nickname);
		void SetPhoneNumber(const std::string& phone_number);
		void SetDarkestSecret(const std::string& darkest_secret);
};

#endif