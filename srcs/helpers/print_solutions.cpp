/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_solutions.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 11:08:38 by tbareich          #+#    #+#             */
/*   Updated: 2022/04/16 13:18:01 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <computor.h>

static double	calculate_discriminant(t_equation equation)
{
	return (ft_pow(equation.coeffs[1], 2)
		- 4 * equation.coeffs[2] * equation.coeffs[0]);
}

static void	print_solution(t_equation equation, double	discriminant)
{
	double	sqrt_discriminant;
	double	x;
	double	y;

	sqrt_discriminant = ft_sqrt(ft_dabs(discriminant));
	x = -equation.coeffs[1] / (2 * equation.coeffs[2]);
	y = sqrt_discriminant / (2 * equation.coeffs[2]);
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
		std::cout << endl << equation.indeterminate_symbol 
			<< "1= -b / (2 * a) + sqrt(Δ) / (2 * a) => ";
		std::cout << equation.indeterminate_symbol 
			<< "1= "<< x << " + " << y << endl;
		std::cout << "                                     => ";
		std::cout << equation.indeterminate_symbol << "1= " << x + y << endl;
		std::cout  << endl<< equation.indeterminate_symbol 
			<< "2= -b / (2 * a) - sqrt(Δ) / (2 * a) => ";
		std::cout << equation.indeterminate_symbol 
			<< "2= "<< x << " - " << y << endl;
		std::cout << "                                     => ";
		std::cout << equation.indeterminate_symbol << "2= " << x - y << endl;
	}
	else
	{
		std::cout << endl << equation.indeterminate_symbol 
			<< "1= -b / (2 * a) + i * sqrt(abs(Δ)) / (2 * a) => ";
		std::cout << equation.indeterminate_symbol << "1= ";
		if (x != .0 )
			std::cout << x;
		if (y != 0)
			std::cout << (x != .0 ? " + " : "") << "i * "
				<< ft_dabs(y) << endl;
		std::cout << endl << equation.indeterminate_symbol 
			<< "2= -b / (2 * a) - i * sqrt(abs(Δ)) / (2 * a) => ";
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
	x = -equation.coeffs[1] / (2 * equation.coeffs[2]);
	y = sqrt_discriminant / (2 * equation.coeffs[2]);
	if (discriminant == 0)
		std::cout
			<< equation.indeterminate_symbol << "= "
			<< fraction_str(to_fraction(-equation.coeffs[1]
				/ (2 * equation.coeffs[2]))) << endl;
	else if (discriminant > 0)
	{
		std::cout << endl << equation.indeterminate_symbol 
			<< "1= -b / (2 * a) + sqrt(Δ) / (2 * a) => ";
		std::cout << equation.indeterminate_symbol 
			<< "1= "<< x << " + " << y << endl;
		std::cout << "                                     => ";
		std::cout << equation.indeterminate_symbol << "1= "
			<< fraction_str(to_fraction(x + y)) << endl;
		std::cout << endl << equation.indeterminate_symbol 
			<< "2= -b / (2 * a) - sqrt(Δ) / (2 * a) => ";
		std::cout << equation.indeterminate_symbol 
			<< "2= "<< x << " - " << y << endl;
		std::cout << "                                     => ";
		std::cout << equation.indeterminate_symbol << "2= "
			<< fraction_str(to_fraction(x - y)) << endl;
	}
	else
	{
		std::cout << endl << equation.indeterminate_symbol 
			<< "1= -b / (2 * a) + i * sqrt(abs(Δ)) / (2 * a) => ";
		fract = to_fraction(x + y);
		std::cout << equation.indeterminate_symbol << "1= "
			<< (x != .0 ? fraction_str(to_fraction(x)) : "");
		if (y != 0)
			std::cout << (x != .0 ? " + " : "") 
				<< "i * " << fraction_str(to_fraction(ft_dabs(y))) << endl;
		std::cout << endl << equation.indeterminate_symbol 
			<< "2= -b / (2 * a) - i * sqrt(abs(Δ)) / (2 * a) => ";
		std::cout << equation.indeterminate_symbol << "2= " 
			<< (x != .0 ? fraction_str(to_fraction(x)) : "");
		if (y != 0)
			std::cout << (x != .0 ? " - " : "")
				<< "i * " << fraction_str(to_fraction(ft_dabs(y))) << endl;
	}
}

void	print_solutions(t_equation equation, int options)
{
	double	discriminant;
	
	discriminant = calculate_discriminant(equation);
	std::cout << "\n-- The discriminant calculation:\n\n";
	std::cout 
		<< "c * X^0 + b * X^1 + a * X^2 = 0 => "
		<< "Δ = b^2 + 4 * a * c\n"
		<< "                                => Δ = "
		<< equation.coeffs[1] << "^2 + 4 * " << equation.coeffs[2] << " * "
		<< equation.coeffs[0] << endl
		<< "                                => Δ = "
		<< discriminant << endl;
	std::cout << "\n-- The solutions:\n\n";
	if (discriminant == 0)
	{
		std::cout << "Discriminant is equal to 0, so the solution is:\n\n";
		std::cout << equation.indeterminate_symbol << "= -b / (2 * a) => ";
	}
	else if (discriminant > 0)
		std::cout 
			<< "Discriminant is strictly positive, so the two solutions are:\n";
	else
		std::cout
			<< "Discriminant is strictly negative, so the two solutions are:\n";
	if (options & FRACTION_OPTION)
		print_solution_fraction(equation, discriminant);
	else
		print_solution(equation, discriminant);
}