/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 10:24:52 by tbareich          #+#    #+#             */
/*   Updated: 2022/04/14 02:02:45 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <computor.h>

static void	print_equation(t_equation equation)
{
	int	first_constant;

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
			std::cout << "- ";
		if (equation.constants[i] != .0)
		{
			std::cout << ft_dabs(equation.constants[i]);
			if (i != 0)
				std::cout << " * X";
			if (i != 1 && i != 0)
				std::cout << "^" << i;
			first_constant = 0;
		}
	}
	std::cout << " = 0" << endl;
	std::cout << "Polynomial degree: " << equation.degree << endl;
}

static void	init_equation(t_equation *equation)
{
	equation->constants[0] = .0;
	equation->constants[1] = .0;
	equation->constants[2] = .0;
	equation->degree = -1;
	equation->position = left;
}

void	reader(int ac, char **av, t_equation *equation)
{
	if (ac != 2)
		usage();
	init_equation(equation);
	find_terms(std::string(av[1]), equation);
	print_equation(*equation);
}