/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hax_uppwer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 09:57:43 by yoav              #+#    #+#             */
/*   Updated: 2022/06/20 13:57:17 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>

#include "libft.h"
#include "ft_printf.h"
#include "generic.h"
#include "base.h"

void	convert_hax_upper(va_list l, void **res, t_flags *f, size_t *len)
{
	unsigned int		nbr;

	nbr = va_arg(l, unsigned int);
	f->is_upper = TRUE;
	convert_generic_unsigned_number(nbr, res, f, BASE_HAX_UPPER);
	if (*res)
		*len += ft_strlen(*(char **)res);
}
