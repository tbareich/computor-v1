/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 20:31:31 by tbareich          #+#    #+#             */
/*   Updated: 2022/04/13 01:21:41 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_abs(int x)
{
	if (x >= 0)
		return (x);
	return (-x);
}

long long	ft_labs(long long x)
{
	if (x >= 0L)
		return (x);
	return (-x);
}

double	ft_dabs(double x)
{
	if (x >= .0)
		return (x);
	return (-x);
}