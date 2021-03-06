/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 09:33:50 by tbareich          #+#    #+#             */
/*   Updated: 2022/04/16 13:32:20 by tbareich         ###   ########.fr       */
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
	return (0);
}