/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SedIsForLosers.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkinsfat <vkinsfat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 13:20:07 by vitakinsfat       #+#    #+#             */
/*   Updated: 2025/02/10 13:39:24 by vkinsfat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SEDISFORLOSERS_HPP
# define SEDISFORLOSERS_HPP

# include <iostream>
# include <fstream>
# include <string.h>

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
