/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 09:57:43 by yoav              #+#    #+#             */
/*   Updated: 2022/06/23 16:17:46 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>

#include "libft.h"
#include "generic.h"
#include "ft_printf.h"
#include "base.h"
#include "printable_mem.h"
#include "handler.h"
#include "convert.h"

t_printable_mem	*convert_ptr(va_list l, t_flag *f)
{
	void	*p;

	p = va_arg(l, void *);
	f->hash = TRUE;
	if (!p)
	{
		f->hash = FALSE;
		return (create_str_to_print(NIL_STR, f, ft_strlen(NIL_STR)));
	}
	return (convert_generic_unsigned_number((size_t)p, f, BASE_HAX_LOWER));
}
