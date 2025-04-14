/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitakinsfator <vitakinsfator@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 20:53:42 by vitakinsfat       #+#    #+#             */
/*   Updated: 2025/04/14 23:36:11 by vitakinsfat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* sharik = new Dog();
	const Animal* murka = new Cat();
	const Animal* animal_array[10];
	
	for (int i = 0; i < 10; i++)
	{
		if (i % 2 == 0)
			animal_array[i] = new Cat();
		else
			animal_array[i] = new Dog();
	}
	for (int i = 0; i < 10; i++)
		animal_array[i]->makeSound();
	sharik->makeSound();
	murka->makeSound();
	for (int i = 0; i < 10; i++)
		delete animal_array[i];
	delete sharik;//should not create a leak
	delete murka;
	return (0);
}
