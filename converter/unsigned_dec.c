/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned_dec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 09:57:43 by yoav              #+#    #+#             */
/*   Updated: 2022/06/20 11:58:47 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>

#include "converter.h"
#include "libft.h"
#include "base.h"

void	convert_unsigned_dec(va_list l, void **res, t_flags *f, size_t *len)
{
	unsigned int		nbr;

	nbr = va_arg(l, unsigned int);
	convert_generic_unsigned_number(nbr, res, f, BASE_DEC_STR);
	if (*res)
		*len += ft_strlen(*(char **)res);
}
