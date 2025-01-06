/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitakinsfator <vitakinsfator@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 14:10:51 by vitakinsfat       #+#    #+#             */
/*   Updated: 2025/01/06 19:47:16 by vitakinsfat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

const std::string& Weapon::getType(void) const
{
	return _type;
}

void Weapon::setType(const std::string& type)
{
	this->_type = type;
}

Weapon::Weapon(const std::string& type)
{
	_type = type;
}

Weapon::Weapon()
{
	_type = "No weapon";
}
