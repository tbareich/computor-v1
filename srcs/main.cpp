/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 09:33:50 by tbareich          #+#    #+#             */
/*   Updated: 2022/04/14 21:20:42 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <computor.h>

int	main(int ac, char **av)
{
	t_equation equation;

	reader(ac, av, &equation);
	solve(equation);
	ft_sqrt(2);
	return (0);
}