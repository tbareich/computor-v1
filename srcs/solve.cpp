/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 21:19:17 by tbareich          #+#    #+#             */
/*   Updated: 2022/04/17 01:28:38 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <computor.h>

void	solve(t_equation equation, int options)
{
	t_fraction fraction;
	
	if (equation.degree < 0)
		std::cout << "This problem has an infinite number of solutions.\n";
	else if (equation.degree == 0)
		std::cout << "This problem have no solution." << endl;
	else if (equation.degree == 1)
	{
		std::cout << "-- The solution is: "
			<< equation.indeterminate_symbol << "= ";
		if (options & FRACTION_OPTION)
		{
			fraction = to_fraction(-equation.coeffs[0] / equation.coeffs[1]);
			std::cout << fraction_str(fraction) << endl;
		}
		else
			if (equation.coeffs[0] == 0)
				std::cout << 0 << endl;
			else
				std::cout << -equation.coeffs[0] / equation.coeffs[1] << endl;
	}
	else
		print_solutions(equation, options);
}
