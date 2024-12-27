/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkinsfat <vkinsfat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 18:09:11 by vkinsfat          #+#    #+#             */
/*   Updated: 2024/12/27 20:40:06 by vkinsfat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
	_name = name;
}

Zombie::~Zombie()
{
    std::cout << "Oh no, " << _name << " died!\n";
}

void Zombie::Announce(void) const
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ...\n";
}
