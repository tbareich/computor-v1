/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 09:33:50 by tbareich          #+#    #+#             */
/*   Updated: 2022/04/16 01:11:11 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <computor.h>

int	main(int ac, char **av)
{
	t_equation	equation;
	int			options;

	set_options(ac, av, &options);
	reader(ac, av, &equation);
	solve(equation, options);
	ft_sqrt(2);
	return (0);
}