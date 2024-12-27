/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkinsfat <vkinsfat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 18:09:13 by vkinsfat          #+#    #+#             */
/*   Updated: 2024/12/27 20:40:30 by vkinsfat         ###   ########.fr       */
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
		Zombie(std::string name);
		~Zombie();
		
		void Announce(void) const;
		static Zombie* newZombie(std::string name);
		static void randomChump(std::string name);
};

#endif