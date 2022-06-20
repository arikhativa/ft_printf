/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generic_number.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 09:57:43 by yoav              #+#    #+#             */
/*   Updated: 2022/06/20 08:37:18 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "converter.h"
#include "base.h"

static int	is_pad(t_flags *f, long nbr)
{
	if (f->plus || f->space || 0 > nbr)
		return (1);
	return (0);
}

static void	add_pad_if_needed(t_flags *f, long nbr, int start, char *ret)
{
	if (0 > nbr)
		ret[start] = '-';
	else if (f->plus)
		ret[start] = '+';
	else if (f->space)
		ret[start] = ' ';
}

void	convert_generic_number(long nbr, void **res, t_flags *f, char *base)
{
	char	*ret;
	int		digit;
	int		pad;
	int		start;

	pad = is_pad(f, nbr);
	digit = count_digit_by_base(nbr, ft_strlen(base));
	ret = generic_create_str(f, (digit + pad));
	start = generic_get_start(f, (digit + pad));
	itoa_base(nbr, base, (ret + pad + start), digit);
	add_pad_if_needed(f, nbr, start, ret);
	*res = ret;
}
