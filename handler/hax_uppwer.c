/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hax_uppwer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 09:57:43 by yoav              #+#    #+#             */
/*   Updated: 2022/06/23 16:11:57 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>

#include "libft.h"
#include "ft_printf.h"
#include "generic.h"
#include "base.h"
#include "printable_mem.h"

t_printable_mem	*convert_hax_upper(va_list l, t_flag *f)
{
	unsigned int		nbr;

	nbr = va_arg(l, unsigned int);
	f->is_upper = TRUE;
	if (0 == nbr)
		f->hash = 0;
	return (convert_generic_unsigned_number(nbr, f, BASE_HAX_UPPER));
}