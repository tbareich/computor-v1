/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_terms.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 22:32:54 by tbareich          #+#    #+#             */
/*   Updated: 2022/04/14 02:08:43 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <computor.h>

void	find_terms(std::string str, t_equation *equation)
{
	std::sregex_iterator words_begin;
    std::sregex_iterator words_end;
	std::regex					exp;
	std::smatch					match;

	str.erase(std::remove_if(str.begin(), str.end(), isspace), str.end());
	equation_validation(str);
	exp = "=|(((\\+|-|)(?=\\d+(\\.\\d+)?|[Xx])(\\d+(\\.\\d+)?)?\\*?([Xx](\
\\^{1}\\d+)?)?))";
	words_begin = std::sregex_iterator(str.begin(), str.end(), exp);
	words_end = std::sregex_iterator();
	for (std::sregex_iterator i = words_begin; i != words_end; ++i)
	{
		match = *i;
		if (match.str().empty())
			break ;
		if (match.str() == "=")
		{
			equation->position = right;
			continue ;
		}
		parse_equation(match.str(), equation);
	}
}