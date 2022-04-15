/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_fraction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 03:34:19 by tbareich          #+#    #+#             */
/*   Updated: 2022/04/15 09:41:04 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mathft.h>

t_fraction to_fraction(double x)
{
	t_fraction	fraction;
	int			gcd;
	int			integral_part;
	int			fractional_part;

	integral_part = ft_floor(x);
	fractional_part = x - integral_part;
	gcd = ft_gcd(ft_round(fractional_part * FRACTION_PRECISION),
		FRACTION_PRECISION);
	fraction.denominator = FRACTION_PRECISION / gcd;
	fraction.nominator = ft_round(fractional_part * FRACTION_PRECISION) / gcd;
	fraction.nominator = (integral_part * fraction.denominator)
		+ fraction.nominator;
	return (fraction);
}