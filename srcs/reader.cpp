/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 10:24:52 by tbareich          #+#    #+#             */
/*   Updated: 2022/04/16 07:00:50 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <computor.h>

static void	print_equation(t_equation equation)
{
	double	first_constant;

	first_constant = 1;
	std::cout << "Reduced form: ";
	for (int i = 0; i < 3; ++i)
	{
		if (!first_constant)
		{
			if (equation.constants[i] < .0)
				std::cout << " - ";
			else if (equation.constants[i] > .0)
				std::cout << " + ";
		}
		else if (equation.constants[i] < .0)
			std::cout << "-";
		if (equation.constants[i] != .0)
		{
			if (ft_dabs(equation.constants[i]) != 1)
				std::cout << ft_dabs(equation.constants[i]);
			if (i != 0 && ft_dabs(equation.constants[i]) != 1)
				std::cout << " * ";
			if (i != 0)
				std::cout << equation.indeterminate_symbol;
			if (i != 1 && i != 0)
				std::cout << "^" << i;
			first_constant = 0;
		}
	}
	if (first_constant)
		std::cout << "0";
	std::cout << " = 0" << endl;
	std::cout << "Polynomial degree: ";
	if (equation.degree >= 0)
		std::cout << equation.degree << endl;
	else
		std::cout << "undefined" << endl;
}

static void	init_equation(t_equation *equation)
{
	equation->constants[0] = .0;
	equation->constants[1] = .0;
	equation->constants[2] = .0;
	equation->degree = -1;
	equation->indeterminate_symbol = 0;
	equation->position = LEFT;
}

void	reader(int ac, char **av, t_equation *equation)
{
	init_equation(equation);
	find_terms(std::string(av[ac - 1]), equation);
	print_equation(*equation);
}