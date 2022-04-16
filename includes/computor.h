/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   computor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 09:58:44 by tbareich          #+#    #+#             */
/*   Updated: 2022/04/16 12:48:09 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPUTOR_H
# define COMPUTOR_H

/*
** libraries
*/

# include <iostream>
# include <string>
# include <regex>

/*
** C libraries
*/
extern "C"
{
	# include <mathft.h>
}

/*
** defines
*/
# ifndef endl
#  define endl "\n"
# endif

# define LEFT 1
# define RIGHT -1

#define FRACTION_OPTION 1

/*
** Error msgs
*/
# define BAD_FORMAT_ERROR "invalid equation format!"
# define DEGREE_LIMITS_ERROR "the polynomial degree is strictly greater than 2\
, I can't solve."
# define MULTI_INDETERS_ERROR "multiple indeterminates is not allowed."
# define EXPONENT_LIMIT_ERROR "exponent out of range."
# define CONSTANT_LIMIT_ERROR "constant out of range."
# define UNKNOWN_ERROR "unknown error."

/*
** structures
*/
typedef struct	s_equation
{
	double	coeffs[3];
	int		degree;
	char	indeterminate_symbol;
	char	position;
}	t_equation;


/*
** functions
*/
void		usage(void);
void		reader(int ac, char **av, t_equation *equation);
void		error(std::string msg);
void		solve(t_equation equation, int options);

void		parse_term(std::string str, t_equation *equation);
void		find_terms(std::string str, t_equation *equation);
void		check_equation_format(std::string str);

void		print_solutions(t_equation equation, int options);
void		set_options(int ac, char **av, int *options);
std::string	fraction_str(t_fraction fraction);

#endif