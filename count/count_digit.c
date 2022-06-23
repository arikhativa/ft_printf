/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_digit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 13:59:32 by yoav              #+#    #+#             */
/*   Updated: 2022/06/23 16:39:51 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	count_digit_by_base(long n, size_t base)
{
	size_t	ret;

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

size_t	count_digit_by_base_unsigned(size_t n, size_t base)
{
	size_t	ret;

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
