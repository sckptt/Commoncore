/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkinsfat <vkinsfat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 14:11:04 by vitakinsfat       #+#    #+#             */
/*   Updated: 2025/02/10 13:36:42 by vkinsfat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"
# include <iostream>
# include <cstddef>

class HumanB
{
	private:
		std::string _nameB;
		Weapon* _weaponB;
		
	public:
		HumanB(const std::string& name);
		
		void setWeapon(Weapon& weapon);
		void attack();
};

#endif