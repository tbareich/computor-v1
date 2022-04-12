/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 10:24:52 by tbareich          #+#    #+#             */
/*   Updated: 2022/04/11 23:59:07 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <computor.h>

static void	parse_equation(std::string str)
{
	
}

static void	search(std::string str)
{
	std::smatch					res;
	std::regex					exp;
	std::string::const_iterator	search_start;

	exp = " *(\\+|-|=)? *(([0-9]+\\.*([0-9]+)?)? *\\*? *)?X{1} \
*(\\^{1} *[0-9]*)?";
	search_start = str.cbegin();
	while (regex_search(search_start, str.cend(), res, exp))
	{
		std::cout << res[0] << endl;
		search_start = res.suffix().first;
	}
}

void	reader(int ac, char **av)
{
	if (ac != 2)
		usage();
	search(av[1]);
}