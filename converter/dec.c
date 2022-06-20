/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dec.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 09:57:43 by yoav              #+#    #+#             */
/*   Updated: 2022/06/20 13:57:02 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>

#include "libft.h"
#include "generic.h"
#include "base.h"

void	convert_dec(va_list l, void **res, t_flags *f, size_t *len)
{
	int		nbr;

	nbr = va_arg(l, int);
	convert_generic_number(nbr, res, f, BASE_DEC_STR);
	if (*res)
		*len += 
		ft_strlen(*(char **)res);
}
