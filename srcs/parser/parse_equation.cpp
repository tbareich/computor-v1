/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_equation.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 22:34:07 by tbareich          #+#    #+#             */
/*   Updated: 2022/04/14 02:06:04 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <computor.h>

static void	set_equation(t_equation *equation, int degree, double constant)
{
	equation->degree = ft_max(equation->degree, degree);
	if (degree == 0)
		equation->constants[0] += (equation->position * constant);
	else if (degree == 1)
	{
		equation->constants[1] += (equation->position * constant);
		if (equation->constants[2] == 0 && equation->constants[1] == 0)
			equation->degree = 0;
	}
	if (degree == 2)
	{
		equation->constants[2] += (equation->position * constant);
		if (equation->constants[2] == 0 && equation->constants[1] == 0)
			equation->degree = 0;
		else if (equation->constants[2] == 0)
			equation->degree = 1;
	}
}

void	parse_equation(std::string str, t_equation *equation)
{
	std::smatch					res;
	std::regex					exp;
	double						constant;
	int							degree;
	
	constant = 1;
	degree = 0;
	exp = "^(\\+|-)?\\d+(\\.\\d+)?";
	if (regex_search(str.cbegin(), str.cend(), res, exp))
		constant = std::stod(res.str());
	exp = "[Xx](\\^{1}\\d+)?$";
	if (regex_search(str.cbegin(), str.cend(), res, exp))
	{
		degree = 1;
		exp = "\\^";
		if (regex_search(res.prefix().first, str.cend(), res, exp))
			degree = std::stoi(res.suffix().str());
	}
	if (degree < 0 || degree > 2)
		error("Bad format");
	set_equation(equation, degree, constant);
}
