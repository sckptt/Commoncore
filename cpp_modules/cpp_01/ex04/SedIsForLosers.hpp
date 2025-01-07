/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SedIsForLosers.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitakinsfator <vitakinsfator@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 13:20:07 by vitakinsfat       #+#    #+#             */
/*   Updated: 2025/01/07 13:55:22 by vitakinsfat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SEDISFORLOSERS_HPP
# define SEDISFORLOSERS_HPP

#include <iostream>
#include <fstream>

class SedIsForLosers
{
	private:
		std::fstream _infile;
		std::fstream _outfile;
		std::string _search;
		std::string _replace;
	public:
		SedIsForLosers(char **av);

		std::string replace(const std::string& line) const;
		void readFile();
};

#endif
