/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generic_number.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 09:57:43 by yoav              #+#    #+#             */
/*   Updated: 2022/06/22 12:38:29 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "converter.h"
#include "generic.h"
#include "count.h"
#include "base.h"
#include "printable_mem.h"
#include "flags.h"

static size_t	get_size_for_number(t_flags *f, size_t nbr_len)
{
	size_t	size;

	size = get_bigger(f->width, nbr_len);
	size = get_bigger(f->precision_value, size);
	return (size);
}

static int	is_pad(t_flags *f, long nbr, size_t digit)
{
	if (f->plus || f->space || (0 > nbr))
		return (1);
	return (0);
}

static void	add_pad_if_needed(t_flags *f, long nbr, int start, char *ret)
{
	if ('0' == f->pad)
		start = 0;
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
	size_t			digit;
	size_t			pad;
	size_t			start;
	size_t			size;

	digit = count_digit_by_base(nbr, ft_strlen(base));
	pad = is_pad(f, nbr, digit);
	size = get_size_for_number(f, (digit + pad));
	ret = generic_create_mem(f, size);
	start = generic_get_start(f, size, (digit + pad));
	add_pad_if_needed(f, nbr, start, ret->mem);
	// add precision() TODO
	itoa_base(nbr, base, (ret->mem + pad + start), digit);
	return (ret);
}
