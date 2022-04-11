/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   computor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 09:58:44 by tbareich          #+#    #+#             */
/*   Updated: 2022/04/11 20:49:48 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPUTOR_H
# define COMPUTOR_H

# include <iostream>
# include <stdlib.h>
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
	int a;
	int	b;
	int	c;
	int	degree;
}	t_equation;


/*
** functions
*/

void	usage(void);
void	reader(int ac, char **av);

#endif