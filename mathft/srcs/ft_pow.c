/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 09:40:22 by tbareich          #+#    #+#             */
/*   Updated: 2022/04/09 20:46:10 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

double	ft_pow(double x, int y)
{
	double	tmp;

	if (y == 0)
		return 1.0;
	tmp = ft_pow(x, y / 2);
	if (y % 2 == 0)
		return tmp * tmp;
	else
	{ 
		if(y > 0)
			return x * tmp * tmp;
		else
			return (tmp * tmp) / x;
	}
}
