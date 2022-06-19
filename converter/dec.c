/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dec.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 09:57:43 by yoav              #+#    #+#             */
/*   Updated: 2022/06/19 15:47:11 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>

#include "converter.h"
#include "base.h"

void	convert_dec(va_list l, void **res, t_flags *f)
{
	char	*ret;
	int		digit;
	int		pad;
	int		nbr;
	int		start;

	nbr = va_arg(l, int);
	pad = 0;
	digit = count_digit_by_base_no_sign((long)nbr, ft_strlen(BASE_DEC));
	if (f->plus || f->space || 0 > nbr)
		pad = 1;
	ret = generic_create_str(f, (digit + pad));
	start = generic_get_start(f, (digit + pad));
	itoa_base_no_sign(nbr, BASE_DEC, (ret + pad + start));
	if (0 > nbr)
		ret[start] = '-';
	else if (f->plus)
		ret[start] = '+';
	else if (f->space)
		ret[start] = ' ';
	*res = ret;
}
