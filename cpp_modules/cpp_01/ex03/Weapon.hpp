/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitakinsfator <vitakinsfator@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 14:10:46 by vitakinsfat       #+#    #+#             */
/*   Updated: 2025/01/06 19:46:40 by vitakinsfat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <string> 

class Weapon
{
	private:
		std::string _type;
		
	public:
		Weapon();
		Weapon(const std::string& type);
		
		const std::string& getType(void) const;
		void setType(const std::string& type);
};

#endif