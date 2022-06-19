/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 13:47:44 by yoav              #+#    #+#             */
/*   Updated: 2022/06/19 15:39:56 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	rec(long n, long base, char *base_str, char *ret)
{
	if (n / base)
	{
		rec(n / base, base, base_str, ret - 1);
		rec(n % base, base, base_str, ret);
	}
	if (n < base)
		*ret = base_str[n];
}

long	count_digit_by_base_no_sign(long n, long base)
{
	long	ret;

	ret = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n /= base;
		++ret;
	}
	return (ret);
}

void	itoa_base_no_sign(int n, char *base_str, char *ret)
{
	long	nbr;
	long	base;
	long	digit;

	nbr = (long)n;
	base = (long)ft_strlen(base_str);
	digit = count_digit_by_base_no_sign(nbr, base);
	if (0 > nbr)
		nbr *= -1;
	rec(nbr, base, base_str, (ret + digit - 1));
}