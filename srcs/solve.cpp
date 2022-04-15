/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 21:19:17 by tbareich          #+#    #+#             */
/*   Updated: 2022/04/15 10:58:39 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <computor.h>

static double	calculate_discriminant(t_equation equation)
{
	return (ft_pow(equation.constants[1], 2)
		- 4 * equation.constants[2] * equation.constants[0]);
}

static void	print_solutions(t_equation equation)
{
	double	discriminant;
	double	sqrt_discriminant;
	
	discriminant = calculate_discriminant(equation);
	if (discriminant == 0)
		std::cout << "Discriminant is equal to 0, so the solution is: "
			<< -ft_pow(equation.constants[1], 2) / 2 * equation.constants[2]
			<< endl;
	else if (discriminant > 0)
	{
		sqrt_discriminant = ft_sqrt(discriminant);
		std::cout 
			<< "Discriminant is strictly positive (Δ = "
			<< discriminant << "), so " << "the two solutions are: " << endl;
		std::cout << equation.p_indeterminate << "1= "
			<< (-equation.constants[1] + sqrt_discriminant)
			/ (2 * equation.constants[2]) << endl;
		std::cout << equation.p_indeterminate << "2= "
			<< (-equation.constants[1] - sqrt_discriminant)
			/ (2 * equation.constants[2]) << endl;
		to_fraction((-equation.constants[1] - sqrt_discriminant)
			/ (2 * equation.constants[2]));
	}
	else
	{
		sqrt_discriminant = ft_sqrt(ft_dabs(discriminant));
		std::cout
			<< "Discriminant is strictly negative (Δ = "
			<< discriminant << "), so " << "the two solutions are: " << endl;
		std::cout << equation.p_indeterminate << "1= "
			<< -equation.constants[1] / (2 * equation.constants[2])
			<< " + i * " << sqrt_discriminant / (2 * equation.constants[2])
			<< endl;
		std::cout << equation.p_indeterminate << "2= "
			<< -equation.constants[1] / (2 * equation.constants[2])
			<< " - i * " << sqrt_discriminant / (2 * equation.constants[2])
			<< endl;
	}
}


static void	print_solutions_fraction(t_equation equation)
{
	double		discriminant;
	double		sqrt_discriminant;
	t_fraction	fraction;
	double		x1;
	double		x2;
	
	discriminant = calculate_discriminant(equation);
	if (discriminant == 0)
		std::cout << "Discriminant is equal to 0, so the solution is: "
			<< -ft_pow(equation.constants[1], 2) / 2 * equation.constants[2]
			<< endl;
	else if (discriminant > 0)
	{
		sqrt_discriminant = ft_sqrt(discriminant);
		x1 = (-equation.constants[1] + sqrt_discriminant) 
			/ (2 * equation.constants[2]);
		x2 = (-equation.constants[1] - sqrt_discriminant) 
			/ (2 * equation.constants[2]);
		fraction = to_fraction(x1);
		std::cout 
			<< "Discriminant is strictly positive (Δ = "
			<< discriminant << "), so " << "the two solutions are: " << endl;
		std::cout << equation.p_indeterminate << "1= "
			<< fraction.nominator;
		if (fraction.denominator != 1)
			std::cout << "/" << fraction.denominator;
		std::cout << endl;
		fraction = to_fraction(x2);
		std::cout << equation.p_indeterminate << "2= "
			<< fraction.nominator;
		if (fraction.denominator != 1)
			std::cout << "/" << fraction.denominator;
		std::cout << endl;
	}
	else
	{
		sqrt_discriminant = ft_sqrt(ft_dabs(discriminant));
		fraction = to_fraction(sqrt_discriminant / (2 * equation.constants[2]));
		std::cout
			<< "Discriminant is strictly negative (Δ = "
			<< discriminant << "), so " << "the two solutions are: " << endl;
		std::cout << equation.p_indeterminate << "1= "
			<< -equation.constants[1] / (2 * equation.constants[2])
			<< " + i * " << fraction.nominator << "/" << fraction.denominator
			<< endl;
		std::cout << equation.p_indeterminate << "2= "
			<< -equation.constants[1] / (2 * equation.constants[2])
			<< " - i * " << fraction.nominator << "/" << fraction.denominator
			<< endl;
	}
}

void	solve(t_equation equation)
{
	std::cout << "\n--- The solution ---\n\n";
	if (equation.degree == -1)
		std::cout << "This problem has an infinite number of solutions.\n";
	else if (equation.degree == 0)
		std::cout << "This problem have no solution." << endl;
	else if (equation.degree == 1)
	{
		std::cout << "The solution is: "
			<< -equation.constants[0] / equation.constants[1] << endl;
	}
	else
	{
		print_solutions(equation);
		std::cout << endl;
		print_solutions_fraction(equation);
	}
}