/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitakinsfator <vitakinsfator@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 14:10:57 by vitakinsfat       #+#    #+#             */
/*   Updated: 2025/01/06 19:38:50 by vitakinsfat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

void HumanA::attack()
{
	std::cout << _nameA << " attacks with their " << _weaponA.getType() << std::endl;
}

HumanA::HumanA(const std::string& name, Weapon& weapon) : _nameA(name), _weaponA(weapon)
{
}
