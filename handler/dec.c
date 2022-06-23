/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dec.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 09:57:43 by yoav              #+#    #+#             */
/*   Updated: 2022/06/23 16:35:37 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>

#include "libft.h"
#include "generic.h"
#include "base.h"
#include "printable_mem.h"

t_printable_mem	*handle_dec(va_list l, t_flag *f)
{
	int	nbr;

	nbr = va_arg(l, int);
	return (convert_generic_number(nbr, f, BASE_DEC_STR));
}
