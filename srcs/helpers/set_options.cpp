/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_options.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 00:29:37 by tbareich          #+#    #+#             */
/*   Updated: 2022/04/16 01:16:25 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <computor.h>

void	set_options(int ac, char **av, int *options)
{
	int		i;

	if (ac >= 2)
	{
		i = 1;
		while (i < ac)
		{
			if (std::strcmp(av[i], "-f") == 0
				|| std::strcmp(av[i], "--fraction") == 0)
			{
				*options |= FRACTION_OPTION;
				--ac;
			}
			if (std::strcmp(av[i], "-h") == 0
				|| std::strcmp(av[i], "--help") == 0)
				usage();
			++i;
		}
	}
	if (ac != 2)
		usage();
}
