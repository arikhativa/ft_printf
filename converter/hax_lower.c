/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hax_lower.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 09:57:43 by yoav              #+#    #+#             */
/*   Updated: 2022/06/20 15:18:55 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>

#include "generic.h"
#include "libft.h"
#include "base.h"
#include "printable_mem.h"

t_printable_mem *convert_hax_lower(va_list l, t_flags *f)
{
	unsigned int		nbr;

	nbr = va_arg(l, unsigned int);
	return (convert_generic_unsigned_number(nbr, f, BASE_HAX_LOWER));
}
