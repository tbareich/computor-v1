/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_terms.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 22:32:54 by tbareich          #+#    #+#             */
/*   Updated: 2022/04/14 23:01:11 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <computor.h>

void	find_terms(std::string str, t_equation *equation)
{
	std::regex				exp;
	std::smatch				match;
	std::sregex_iterator	term_begin;
    std::sregex_iterator	term_end;

	str.erase(std::remove_if(str.begin(), str.end(), isspace), str.end());
	check_equation_format(str);
	exp = "=|((\\+|-)?(?!$|\\+|-|=)((\\d+(\\.\\d+)?)?(\\*(?=[A-z]))?\
([A-z](\\^\\d+)?)?)(?=\\+|-|=|$))";
	term_begin = std::sregex_iterator(str.begin(), str.end(), exp);
	term_end = std::sregex_iterator();
	for (std::sregex_iterator i = term_begin; i != term_end; ++i)
	{
		match = *i;
		if (match.str().empty())
			break ;
		if (match.str() == "=")
		{
			equation->position = RIGHT;
			continue ;
		}
		parse_term(match.str(), equation);
	}
}