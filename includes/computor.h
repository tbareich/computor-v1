/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   computor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 09:58:44 by tbareich          #+#    #+#             */
/*   Updated: 2022/04/15 04:28:39 by tbareich         ###   ########.fr       */
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

/*
** Error msgs
*/
# define BAD_FORMAT_ERROR "invalid equation format!"
# define DEGREE_LIMITS_ERROR "the polynomial degree is strictly greater than 2\
, I can't solve."
# define MULTI_INDETERS_ERROR "multiple indeterminates are not allowed."

/*
** structures
*/
typedef struct	s_equation
{
	double	constants[3];
	int		degree;
	char	p_indeterminate;
	char	position;
}	t_equation;


/*
** functions
*/
void	usage(void);
void	reader(int ac, char **av, t_equation *equation);
void	error(std::string msg);
void	solve(t_equation equation);

void	parse_term(std::string str, t_equation *equation);
void	find_terms(std::string str, t_equation *equation);
void	check_equation_format(std::string str);

#endif