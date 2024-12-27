/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkinsfat <vkinsfat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 20:39:16 by vkinsfat          #+#    #+#             */
/*   Updated: 2024/12/27 20:59:36 by vkinsfat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void)
{
    _name = "Dead Johnny";
}

Zombie::~Zombie()
{
    std::cout << "Oh no, " << _name << " died!\n";
}

void Zombie::Announce(void) const
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ...\n";
}

const std::string& Zombie::GetName() const
{
    return _name;
}

void Zombie::SetName(const std::string& name)
{
    _name = name;
}
