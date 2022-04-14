/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equation_validation.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 00:56:47 by tbareich          #+#    #+#             */
/*   Updated: 2022/04/14 02:05:34 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <computor.h>

void	equation_validation(std::string str)
{
	std::smatch	match;
	std::regex	exp;

	exp = "^(((\\+|-|)(?=\\d+(\\.\\d+)?|[Xx])(\\d+(\\.\\d+)?)?\\*?([Xx](\\^{1}\
\\d+)?)?))+={1}(((\\+|-|)(?=\\d+(\\.\\d+)?|[Xx])(\\d+(\\.\\d+)?)?\\*?([Xx](\
\\^{1}\\d+)?)?))+$";
	if (std::regex_match(str, exp))
		return ;
	error("Bad format");
}
