/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_term.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 22:34:07 by tbareich          #+#    #+#             */
/*   Updated: 2022/04/16 10:31:04 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <computor.h>

static void	update_equation(t_equation *equation, int degree, double constant)
{
	equation->degree = ft_max(equation->degree, degree);
	if (degree == 0)
	{
		equation->coeffs[0] += (equation->position * constant);
		if (equation->coeffs[0] == 0)
			if (equation->coeffs[2] == 0 && equation->coeffs[1] == 0)
				equation->degree = -1;
	}
	else if (degree == 1)
	{
		equation->coeffs[1] += (equation->position * constant);
		if (equation->coeffs[1] == 0)
		{
			if (equation->coeffs[2] != 0)
				equation->degree = 2;
			else if (equation->coeffs[0] != 0)
				equation->degree = 0;
			else 
				equation->degree = -1;
		}
	}
	else if (degree == 2)
	{
		equation->coeffs[2] += (equation->position * constant);
		if (equation->coeffs[2] == 0)
		{
			if (equation->coeffs[1] != 0)
				equation->degree = 1;
			else if (equation->coeffs[0] != 0)
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
	char		indeterminate_symbol;
	
	try
	{
		constant = 1;
		degree = 0;
		exp = "^(\\+|-)?\\d+(\\.\\d+)?";
		if (regex_search(str.cbegin(), str.cend(), res, exp))
			constant = std::stod(res.str());
		else if (str[0] == '-')
			constant *= -1;
		exp = "[A-z]{1}(\\^\\d+)?$";
		if (regex_search(str.cbegin(), str.cend(), res, exp))
		{
			indeterminate_symbol = std::toupper(res.str(0)[0]);
			if (equation->indeterminate_symbol == 0)
				equation->indeterminate_symbol = indeterminate_symbol;
			else if (equation->indeterminate_symbol != indeterminate_symbol)
				error(MULTI_INDETERS_ERROR);
			degree = 1;
			exp = "\\^";
			if (regex_search(res.prefix().first, str.cend(), res, exp))
				degree = std::stoi(res.suffix().str());
		}
		if (degree > 2 && constant != 0)
			error(DEGREE_LIMITS_ERROR);
		else if (degree > 2 && constant == 0)
			degree = -1;
		update_equation(equation, degree, constant);
	}
	catch(const std::exception& e)
	{
		if (std::strcmp(e.what(), "stoi: out of range") == 0)
			error(EXPONENT_LIMIT_ERROR);
		else if (std::strcmp(e.what(), "stod: out of range") == 0)
			error(CONSTANT_LIMIT_ERROR);
		else
			error(UNKNOWN_ERROR);
	}
}
