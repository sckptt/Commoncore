/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SedIsForLosers.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkinsfat <vkinsfat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 14:02:03 by vitakinsfat       #+#    #+#             */
/*   Updated: 2025/02/10 14:32:12 by vkinsfat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SedIsForLosers.hpp"

std::string SedIsForLosers::replace(const std::string& line) const
{
	std::size_t occ;
	std::size_t i = 0;
	std::string result;
	
	while (i < line.length())
	{
		occ = line.find(_search, i);
		if (occ == std::string::npos && i == 0)
		{
			result = line;
			break ;
		}
		else if (occ != std::string::npos)
		{
			result.append(line.substr(i, occ - i));
			result.append(_replace);
			i = occ + _search.length();
		}
		else if (occ == std::string::npos && i != 0)
		{
			result.append(line.substr(i, line.length()));
			break ;
		}
	}
	return result;
}

void SedIsForLosers::readFile(void)
{
	std::string line;
	std::string result;
	
	if (_search.length() == 0)
		throw std::runtime_error("Search string can't have zero length!");
	if (_replace.length() == 0)
		throw std::runtime_error("Replace string can't have zero length!");
	while (getline(_infile, line))
	{
		result = replace(line);
		_outfile << result << std::endl;
	}
	_infile.close();
	_outfile.close();
}

SedIsForLosers::SedIsForLosers(char **av)
{
	std::string filename;

	filename = std::string(av[1]) + ".replace";
	if (strlen(av[1]) == 0)
		throw std::runtime_error("Filename string can't have zero length!");
	_infile.open(av[1], std::ios::in);
	if (!_infile.is_open())
		throw std::runtime_error("Error in opening infile!");
	_outfile.open(filename.c_str(), std::ios::out | std::ios::trunc);
	if (!_outfile.is_open())
	{
		_infile.close();	
		throw std::runtime_error("Error in opening outfile!");
	}
	_search = std::string(av[2]);
	_replace = std::string(av[3]);
}
