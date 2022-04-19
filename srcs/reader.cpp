/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 10:24:52 by tbareich          #+#    #+#             */
/*   Updated: 2022/04/19 07:00:13 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <computor.h>

static void	print_equation(t_equation equation)
{
	double	first_constant;

	first_constant = 1;
	std::cout << "\n-- Reduced form: ";
	for (int i = 0; i < (int)equation.coeffs.size(); ++i)
	{
		if (!first_constant)
		{
			if (equation.coeffs[i] < .0)
				std::cout << " - ";
			else if (equation.coeffs[i] > .0)
				std::cout << " + ";
		}
		else if (equation.coeffs[i] < .0)
			std::cout << "-";
		if (equation.coeffs[i] != .0)
		{
			std::cout << ft_dabs(equation.coeffs[i]) << " * "
				<< (equation.indeterminate_symbol
				? equation.indeterminate_symbol : 'X') << "^" << i;
			first_constant = 0;
		}
	}
	if (first_constant)
		std::cout << "0 * " << (equation.indeterminate_symbol != 0
		? equation.indeterminate_symbol : 'X') << " ^ (−∞)";
	std::cout << " = 0" << endl << "\n-- Polynomial degree: ";
	if (equation.degree >= 0)
		std::cout << equation.degree << "\n\n";
	else
		std::cout << "−∞\n\n";
	if (equation.degree > 2)
		error(DEGREE_LIMITS_ERROR);
}

static void	init_equation(t_equation *equation)
{
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