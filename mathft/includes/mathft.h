/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mathft.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 10:36:20 by tbareich          #+#    #+#             */
/*   Updated: 2022/04/15 10:56:23 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATHFT_H
# define MATHFT_H

/*
** macros
*/

# ifndef ROOT_APPR
#  define ROOT_APPR 0.00000000001
# endif

# ifndef NAN
#  define NAN 0.f / 0.f
# endif

# ifndef FRACTION_PRECISION
#  define FRACTION_PRECISION 1e2
# endif

/*
** structures
*/

typedef struct s_fraction
{
	int	nominator;
	int	denominator;
}	t_fraction;

/*
** functions
*/

double		ft_root(double arg1, double arg2);
double		ft_sqrt(double arg);

double		ft_pow(double x, int y);

int			ft_abs(int x);
long long	ft_labs(long long x);
double		ft_dabs(double x);
int			ft_round(double x);
int			ft_floor(double x);


char		ft_isnan(double x);

int			ft_max(int x, int y);
int			ft_min(int x, int y);
double		ft_dmax(double x, double y);
double		ft_dmin(double x, double y);

int			ft_gcd(int a, int b);
long long	ft_lgcd(long long a, long long b);

t_fraction 	to_fraction(double x);

#endif
