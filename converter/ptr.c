/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 09:57:43 by yoav              #+#    #+#             */
/*   Updated: 2022/06/20 11:59:15 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>

#include "libft.h"
#include "converter.h"
#include "ft_printf.h"
#include "base.h"

void	convert_ptr(va_list l, void **res, t_flags *f, size_t *len)
{
	void	*p;

	p = va_arg(l, void *);
	f->hash = TRUE;
	convert_generic_unsigned_number((size_t)p, res, f, BASE_HAX_LOWER);
	if (*res)
		*len += ft_strlen(*(char **)res);
}
