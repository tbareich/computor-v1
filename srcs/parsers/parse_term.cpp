/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_term.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 22:34:07 by tbareich          #+#    #+#             */
/*   Updated: 2022/04/15 10:54:43 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <computor.h>

static void	update_equation(t_equation *equation, int degree, double constant)
{
	equation->degree = ft_max(equation->degree, degree);
	if (degree == 0)
	{
		equation->constants[0] += (equation->position * constant);
		if (equation->constants[0] == 0)
			if (equation->constants[2] == 0 && equation->constants[1] == 0)
				equation->degree = -1;
	}
	else if (degree == 1)
	{
		equation->constants[1] += (equation->position * constant);
		if (equation->constants[1] == 0)
		{
			if (equation->constants[2] != 0)
				equation->degree = 2;
			else if (equation->constants[0] != 0)
				equation->degree = 0;
			else 
				equation->degree = -1;
		}
	}
	else if (degree == 2)
	{
		equation->constants[2] += (equation->position * constant);
		if (equation->constants[2] == 0)
		{
			if (equation->constants[1] != 0)
				equation->degree = 1;
			else if (equation->constants[0] != 0)
				equation->degree = 0;
			else 
				equation->degree = -1;
		}
	}
}

void	parse_term(std::string str, t_equation *equation)
{
	std::regex	exp;
	std::smatch	res;
	double		constant;
	int			degree;
	char		p_indeterminate;
	
	constant = 1;
	degree = 0;
	exp = "^(\\+|-)?\\d+(\\.\\d+)?";
	if (regex_search(str.cbegin(), str.cend(), res, exp))
		constant = std::stod(res.str());
	exp = "[A-z]{1}(\\^\\d+)?$";
	if (regex_search(str.cbegin(), str.cend(), res, exp))
	{
		p_indeterminate = std::toupper(res.str(0)[0]);
		if (equation->p_indeterminate == 0)
			equation->p_indeterminate = p_indeterminate;
		else if (equation->p_indeterminate != p_indeterminate)
			error(MULTI_INDETERS_ERROR);
		degree = 1;
		exp = "\\^";
		if (regex_search(res.prefix().first, str.cend(), res, exp))
			degree = std::stoi(res.suffix().str());
	}
	if (degree > 2)
		error(DEGREE_LIMITS_ERROR);
	update_equation(equation, degree, constant);
}
