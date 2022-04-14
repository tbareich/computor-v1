/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   computor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 09:58:44 by tbareich          #+#    #+#             */
/*   Updated: 2022/04/14 02:05:28 by tbareich         ###   ########.fr       */
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

# define left 1
# define right -1

/*
** structures
*/
typedef struct	s_equation
{
	double	constants[3];
	int		degree;
	char	position;
}	t_equation;


/*
** functions
*/
void	usage(void);
void	reader(int ac, char **av, t_equation *equation);
void	error(std::string msg);

void	parse_equation(std::string str, t_equation *equation);
void	find_terms(std::string str, t_equation *equation);
void	equation_validation(std::string str);

#endif