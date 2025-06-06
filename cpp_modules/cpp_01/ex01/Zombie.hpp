/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkinsfat <vkinsfat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 20:39:38 by vkinsfat          #+#    #+#             */
/*   Updated: 2025/02/10 13:32:39 by vkinsfat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>
# include <cstdlib>

class Zombie
{
	private:
		std::string _name;

	public:
		Zombie();
		~Zombie();
		
		void announce(void) const;
		Zombie* zombieHorde(int N, std::string name);
		const std::string &getName(void) const;
		void setName(const std::string& name);
};

#endif