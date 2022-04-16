/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 10:26:19 by tbareich          #+#    #+#             */
/*   Updated: 2022/04/16 01:18:09 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <computor.h>

void	usage(void)
{
	std::cerr << "Usage: " << endl
	<< "\t./computor [-f|--fraction|-h|--help] <equation>" << endl;
	std::cerr << "Options:" << endl
	<< "\t-f --fraction\tDisplay solution(s) as an irreducible fraction."
	<< endl << "\t-h --help\tShow this screen." << endl;
	exit(1);
}