/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitakinsfator <vitakinsfator@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 20:39:16 by vkinsfat          #+#    #+#             */
/*   Updated: 2025/01/06 14:55:28 by vitakinsfat      ###   ########.fr       */
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

void Zombie::announce(void) const
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ...\n";
}

const std::string& Zombie::getName() const
{
    return _name;
}

void Zombie::setName(const std::string& name)
{
    _name = name;
}
