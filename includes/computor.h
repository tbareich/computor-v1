/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   computor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 09:58:44 by tbareich          #+#    #+#             */
/*   Updated: 2022/04/11 22:01:13 by tbareich         ###   ########.fr       */
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
# include <mathft.h>

/*
** defines
*/
# ifndef endl
#  define endl "\n"
# endif

/*
** structures
*/
typedef struct	s_equation
{
	double	a;
	double	b;
	double	c;
	int		degree;
}	t_equation;


/*
** functions
*/
void	usage(void);
void	reader(int ac, char **av);

#endif