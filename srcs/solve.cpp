/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 21:19:17 by tbareich          #+#    #+#             */
/*   Updated: 2022/04/16 07:01:18 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <computor.h>

void	solve(t_equation equation, int options)
{
	t_fraction fraction;
	
	std::cout << "\n--\n";
	if (equation.degree == -1)
		std::cout << "This problem has an infinite number of solutions.\n";
	else if (equation.degree == 0)
		std::cout << "This problem have no solution." << endl;
	else if (equation.degree == 1)
	{
		if (options & FRACTION_OPTION)
		{
			fraction = to_fraction(-equation.constants[0] 
				/ equation.constants[1]);
			std::cout << "The solution is: " << endl
				<< equation.indeterminate_symbol << "= "
				<< fraction.nominator;
			if (fraction.denominator != 1)
				std::cout << "/" << fraction.denominator;
			std::cout << endl;
		}
		else
			std::cout << "The solution is: " << endl
				<< equation.indeterminate_symbol << "= "
				<< -equation.constants[0] / equation.constants[1]
				<< endl;
	}
	else
		print_solutions(equation, options);
}
