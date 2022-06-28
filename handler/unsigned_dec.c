/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned_dec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 09:57:43 by yoav              #+#    #+#             */
/*   Updated: 2022/06/28 12:28:57 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>

#include "generic.h"
#include "base.h"
#include "printable_mem.h"

t_printable_mem	*handle_unsigned_dec(va_list l, t_flag *f)
{
	unsigned int		nbr;

	nbr = va_arg(l, unsigned int);
	return (convert_generic_unsigned_number(nbr, f, BASE_DEC_STR));
}
