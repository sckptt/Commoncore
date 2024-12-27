/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkinsfat <vkinsfat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 20:39:38 by vkinsfat          #+#    #+#             */
/*   Updated: 2024/12/27 20:59:58 by vkinsfat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>

class Zombie
{
	private:
		std::string _name;

	public:
		Zombie();
		~Zombie();
		
		void Announce(void) const;
		Zombie* zombieHorde(int N, std::string name);
		const std::string &GetName(void) const;
		void SetName(const std::string& name);
};

#endif