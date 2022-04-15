/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_equation_format.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 00:56:47 by tbareich          #+#    #+#             */
/*   Updated: 2022/04/15 04:25:41 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <computor.h>

void	check_equation_format(std::string str)
{
	std::smatch	match;
	std::regex	exp;

	exp = "^((\\+|-)?(?!$|\\+|-|=)((\\d+(\\.\\d+)?)?(\\*(?=[A-z]))?\
([A-z](\\^\\d+)?)?)(?=\\+|-|=|$))+={1}((\\+|-)?(?!$|\\+|-)((\\d+(\\.\\d+)?)?\
(\\*(?=[A-z]))?([A-z](\\^\\d+)?)?)(?=\\+|-|$))+$";
	if (std::regex_match(str, exp))
		return ;
	error(BAD_FORMAT_ERROR);
}