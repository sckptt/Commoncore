/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkinsfat <vkinsfat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 18:42:46 by vkinsfat          #+#    #+#             */
/*   Updated: 2025/02/14 14:49:49 by vkinsfat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

std::ostream& operator<<(std::ostream& os, const Fixed& obj)
{
	os << obj.toFloat();
	return os;
}

int main(void) 
{
	Fixed a;
	
	Fixed const b(Fixed(5.05f) + Fixed(2));
	Fixed const c(Fixed(5.05f) - Fixed(2));
	Fixed const d(Fixed(5.05f) * Fixed(2));
	Fixed const e(Fixed(5.05f) / Fixed(2));
	
	bool f(Fixed(123) > Fixed(8));
	bool g(Fixed(123) < Fixed(8));
	bool h(Fixed(123) >= Fixed(8));
	bool i(Fixed(123) <= Fixed(8));
	bool j(Fixed(123) == Fixed(8));
	bool k(Fixed(123) != Fixed(8));

	std::cout <<std::boolalpha;
	
	std::cout << "Comparison check:\n" << f << std::endl;
	std::cout << g << std::endl;
	std::cout << h << std::endl;
	std::cout << i << std::endl;
	std::cout << j << std::endl;
	std::cout << k << std::endl;

	std::cout << "\nArithmetic check:\n" << b << std::endl;
	std::cout << c << std::endl;
	std::cout << d << std::endl;
	std::cout << e << std::endl;
	
	std::cout << "\nIncrement/decrement check:\n" << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << --a << std::endl;
	std::cout << a << std::endl;
	std::cout << a-- << std::endl;
	std::cout << a << std::endl;

	std::cout << "\nMin/max check:" << std::endl;
	std::cout << Fixed::max(a, b) << std::endl;
	std::cout << Fixed::min(b, c) << std::endl;
	return 0;
}
