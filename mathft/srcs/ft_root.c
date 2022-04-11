/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_root.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 01:37:25 by tbareich          #+#    #+#             */
/*   Updated: 2022/04/11 01:28:20 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mathft.h>

/*
** Newton's Method for Finding Equation Roots
*/
double	ft_root(double arg1, double arg2)
{
	double	x;
	double	root;

	x = arg1;
	if (arg2 < 1)
		return (NAN);
	if (arg1 == .0)
		return (arg1);
	/*
	** Xn+1 = Xn - f(Xn) / f'(Xn)
	** x = root(z, y)
	** f(x) = x ** y - z
	** f'(x) = y * x ** (y - 1)
	*/
	while (1)
	{
		root = x - (ft_pow(x, arg2) - arg1) / (arg2 * ft_pow(x, arg2 - 1));
		if (ft_isnan(root) || ft_fabs(x - root) < ROOT_APPR)
			break ;
		x = root;
	}
	return (root);
}