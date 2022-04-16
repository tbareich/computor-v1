/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_solutions.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 11:08:38 by tbareich          #+#    #+#             */
/*   Updated: 2022/04/16 07:00:53 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <computor.h>

static double	calculate_discriminant(t_equation equation)
{
	return (ft_pow(equation.constants[1], 2)
		- 4 * equation.constants[2] * equation.constants[0]);
}

static std::string	str_fraction(t_fraction fraction)
{
	if (fraction.nominator == 0)
		return ("0");
	if (fraction.denominator != 1)
		return (std::to_string(fraction.nominator) + "/"
			+ std::to_string(fraction.denominator));
	return (std::to_string(fraction.nominator));
}

static void	print_solution(t_equation equation, double	discriminant)
{
	double	sqrt_discriminant;
	double	x;
	double	y;

	sqrt_discriminant = ft_sqrt(ft_dabs(discriminant));
	x = -equation.constants[1] / (2 * equation.constants[2]);
	y = sqrt_discriminant / (2 * equation.constants[2]);
	if (discriminant == 0)
	{
		std::cout
			<< equation.indeterminate_symbol << "= ";
		if (x != 0)
			std::cout << x << endl;
		else
			std::cout << 0 << endl;
	}
	else if (discriminant > 0)
	{
		std::cout << equation.indeterminate_symbol << "1= " << x + y << endl;
		std::cout << equation.indeterminate_symbol << "2= " << x - y << endl;
	}
	else
	{
		std::cout << equation.indeterminate_symbol << "1= ";
		if (x != .0 )
			std::cout << x;
		if (y != 0)
			std::cout << (x != .0 ? " + " : "") << "i * "
				<< ft_dabs(y) << endl;
		std::cout << equation.indeterminate_symbol << "2= ";
		if (x != .0 )
			std::cout << x;
		if (y != 0)
			std::cout << (x != .0 ? " - " : "") << "i * "
				<< ft_dabs(y) << endl;
	}
}

static void	print_solution_fraction(t_equation equation, double	discriminant)
{
	double		sqrt_discriminant;
	double		x;
	double		y;
	t_fraction	fract;

	sqrt_discriminant = ft_sqrt(ft_dabs(discriminant));
	x = -equation.constants[1] / (2 * equation.constants[2]);
	y = sqrt_discriminant / (2 * equation.constants[2]);
	if (discriminant == 0)
		std::cout
			<< equation.indeterminate_symbol << "= "
			<< str_fraction(to_fraction(-equation.constants[1]
				/ (2 * equation.constants[2])))
			<< endl;
	else if (discriminant > 0)
	{
		std::cout << equation.indeterminate_symbol << "1= "
			<< str_fraction(to_fraction(x + y)) << endl;
		std::cout << equation.indeterminate_symbol << "2= "
			<< str_fraction(to_fraction(x - y)) << endl;
	}
	else
	{
		fract = to_fraction(x + y);
		std::cout << equation.indeterminate_symbol << "1= "
			<< (x != .0 ? str_fraction(to_fraction(x)) : "");
		if (y != 0)
			std::cout << (x != .0 ? " + " : "") 
				<< "i * " << str_fraction(to_fraction(ft_dabs(y))) << endl;
		std::cout << equation.indeterminate_symbol << "2= " 
			<< (x != .0 ? str_fraction(to_fraction(x)) : "");
		if (y != 0)
			std::cout << (x != .0 ? " - " : "")
				<< "i * " << str_fraction(to_fraction(ft_dabs(y))) << endl;
	}
}

void	print_solutions(t_equation equation, int options)
{
	double	discriminant;
	
	discriminant = calculate_discriminant(equation);
	if (discriminant == 0)
		std::cout << "Discriminant is equal to 0, so the solution is:" << endl;
	else if (discriminant > 0)
		std::cout 
			<< "Discriminant is strictly positive (Δ = "
			<< discriminant << "), so " << "the two solutions are:" << endl;
	else
		std::cout
			<< "Discriminant is strictly negative (Δ = "
			<< discriminant << "), so " << "the two solutions are:" << endl;
	if (options & FRACTION_OPTION)
		print_solution_fraction(equation, discriminant);
	else
		print_solution(equation, discriminant);
}