/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generic_unsigned_number.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 09:57:43 by yoav              #+#    #+#             */
/*   Updated: 2022/06/20 08:36:50 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "converter.h"
#include "base.h"

static int	get_pad(t_flags *f)
{
	if (f->hash)
		return (2);
	return (0);
}

static void	add_pad_if_needed(t_flags *f, size_t start, char *ret)
{
	if (f->hash && f->is_upper)
		ft_memcpy((ret + start), HEX_MARK_UPPER, ft_strlen(HEX_MARK_UPPER));
	else if (f->hash)
		ft_memcpy((ret + start), HEX_MARK_LOWER, ft_strlen(HEX_MARK_LOWER));
}

void	convert_generic_unsigned_number(\
					size_t nbr, void **res, t_flags *f, char *base)
{
	char	*ret;
	size_t	digit;
	size_t	start;
	size_t	pad;

	digit = count_digit_by_base_unsigned(nbr, ft_strlen(base));
	pad = get_pad(f);
	ret = generic_create_str(f, (digit + pad));
	start = generic_get_start(f, (digit + pad));
	stoa_base(nbr, base, (ret + start + pad), digit);
	add_pad_if_needed(f, start, ret);
	*res = ret;
}