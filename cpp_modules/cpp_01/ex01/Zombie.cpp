/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkinsfat <vkinsfat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 20:39:16 by vkinsfat          #+#    #+#             */
/*   Updated: 2025/02/10 13:27:13 by vkinsfat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void)
{
    _name = "Dead Johnny";
}

Zombie::~Zombie()
{
    std::cout << "Oh no, " << _name << " died!" << std::endl;
}

void Zombie::announce(void) const
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

const std::string& Zombie::getName() const
{
    return _name;
}

void Zombie::setName(const std::string& name)
{
    _name = name;
}
