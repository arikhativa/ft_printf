/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generic_number.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 09:57:43 by yoav              #+#    #+#             */
/*   Updated: 2022/06/21 14:05:13 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "converter.h"
#include "generic.h"
#include "count.h"
#include "base.h"
#include "printable_mem.h"
#include "flags.h"

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

t_printable_mem	*convert_generic_number(long nbr, t_flags *f, char *base)
{
	t_printable_mem	*ret;
	int				digit;
	int				pad;
	int				start;

	pad = is_pad(f, nbr);
	digit = count_digit_by_base(nbr, ft_strlen(base));
	ret = generic_create_mem(f, (digit + pad));
	start = generic_get_start(f, (digit + pad));
	itoa_base(nbr, base, (ret->mem + pad + start), digit);
	add_pad_if_needed(f, nbr, start, ret->mem);
	return (ret);
}
