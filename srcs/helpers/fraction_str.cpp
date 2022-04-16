/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fraction_str.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 09:48:20 by tbareich          #+#    #+#             */
/*   Updated: 2022/04/16 09:56:36 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <computor.h>

std::string	fraction_str(t_fraction fraction)
{
	if (fraction.nominator == 0)
		return ("0");
	if (fraction.denominator != 1)
		return (std::to_string(fraction.nominator) + "/"
			+ std::to_string(fraction.denominator));
	return (std::to_string(fraction.nominator));
}
