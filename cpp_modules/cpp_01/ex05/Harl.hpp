/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkinsfat <vkinsfat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 14:29:19 by vitakinsfat       #+#    #+#             */
/*   Updated: 2025/02/10 13:39:29 by vkinsfat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>

class Harl
{
	private:
		void debug(void) const;
		void info(void) const;
		void warning(void) const;
		void error(void) const;
	public:
		void complain(std::string level);
		typedef void (Harl::*HarlFuncs)(void) const;
};

#endif