/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 13:47:44 by yoav              #+#    #+#             */
/*   Updated: 2022/06/19 14:01:08 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long	count_digit_by_base(long n, long base)
{
	long	ret;

	ret = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		++ret;
	while (n)
	{
		n /= base;
		++ret;
	}
	return (ret);
}

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

void	itoa_base(int n, char *base_str, char *ret)
{
	long	nbr;
	long	base;
	long	digit;

	nbr = (long)n;
	base = (long)ft_strlen(base_str);
	digit = count_digit_by_base(nbr, base);
	if (0 > nbr)
	{
		*ret = '-';
		nbr *= -1;
	}
	rec(nbr, base, base_str, (ret + digit - 1));
}