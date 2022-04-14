/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 10:42:43 by tbareich          #+#    #+#             */
/*   Updated: 2022/04/12 02:05:48 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mathft.h>

double	ft_sqrt(double arg)
{
	double	x;
	double	root;

	x = arg;
	if (arg < .0)
		return (NAN);
	if (arg == .0)
		return (arg);
	while (1)
	{
		root = x - (ft_pow(x, 2) - arg) / (2 * x);
		if (ft_isnan(root) || ft_dabs(x - root) < ROOT_APPR)
			break ;
		x = root;
	}
	return (root);
}