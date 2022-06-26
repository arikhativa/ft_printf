/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generic_number.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 09:57:43 by yoav              #+#    #+#             */
/*   Updated: 2022/06/26 18:12:49 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "libft.h"
#include "convert.h"
#include "generic.h"
#include "count.h"
#include "base.h"
#include "printable_mem.h"
#include "flag.h"

static int	is_pad(t_flag *f, long nbr)
{
	if (f->plus || f->space || (0 > nbr))
		return (1);
	return (0);
}

static size_t	add_pad_if_needed(t_flag *f, long nbr, size_t start, char *ret)
{
	size_t	i;

	i = start;
	if ('0' == f->pad)
		i = 0;
	if (0 > nbr)
	{
		ret[i] = '-';
		++start;
	}
	else if (f->plus)
	{
		ret[i] = '+';
		++start;
	}
	else if (f->space)
	{
		ret[i] = ' ';
		++start;
	}
	return (start);
}

t_printable_mem	*convert_generic_number(long nbr, t_flag *f, char *base)
{
	t_printable_mem	*ret;
	size_t			digit;
	size_t			pad;
	size_t			i;
	size_t			size;

	digit = count_digit_by_base(nbr, ft_strlen(base));
	pad = is_pad(f, nbr);
	size = get_size_for_number(f, digit, pad);
	ret = create_printable_mem(f, size);
	if (!ret)
		return (NULL);
	i = generic_get_start(f, size, digit, pad);
	i = add_pad_if_needed(f, nbr, i, ret->mem);
	i = add_precision_pad(ret->mem, i, f, digit);
	itoa_base(nbr, base, (ret->mem + i), digit);
	return (ret);
}
