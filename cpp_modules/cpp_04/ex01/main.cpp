/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitakinsfator <vitakinsfator@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 20:53:42 by vitakinsfat       #+#    #+#             */
/*   Updated: 2025/04/14 22:26:17 by vitakinsfat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* zhvtne = new Animal();
	const Animal* sharik = new Dog();
	const Animal* murka = new Cat();
	const WrongAnimal* anml = new WrongAnimal();
	const WrongAnimal* shmurka = new WrongCat();
	
	std::cout << sharik->getType() << " " << std::endl;
	std::cout << murka->getType() << " " << std::endl;
	std::cout << zhvtne->getType() << " " << std::endl;
	std::cout << anml->getType() << " " << std::endl;
	std::cout << shmurka->getType() << " " << std::endl;
	murka->makeSound(); //will output the cat sound!
	sharik->makeSound();
	zhvtne->makeSound();
	anml->makeSound();
	shmurka->makeSound();
	delete zhvtne;
	delete sharik;
	delete murka;
	delete anml;
	delete shmurka;
	return (0);
}
