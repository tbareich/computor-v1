/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gcd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 03:26:57 by tbareich          #+#    #+#             */
/*   Updated: 2022/04/15 10:15:38 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mathft.h>

int	ft_gcd(int a, int b)
{
	if (a == 0)
		return b;
	else if (b == 0)
		return a;
	if (a < b)
		return ft_gcd(a, b % a);
	else
		return ft_gcd(b, a % b);
}

long long	ft_lgcd(long long a, long long b)
{
	if (a == 0)
		return b;
	else if (b == 0)
		return a;
	if (a < b)
		return ft_lgcd(a, b % a);
	else
		return ft_lgcd(b, a % b);
}