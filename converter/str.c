/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 12:39:34 by yoav              #+#    #+#             */
/*   Updated: 2022/06/23 11:42:40 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>

#include "flags.h"
#include "libft.h"
#include "parser.h"
#include "generic.h"
#include "printable_mem.h"
#include "converter.h"

inline static size_t	get_size_for_str(t_flags *f, size_t len)
{
	return (get_bigger(f->width, len));
}

static size_t	get_start_for_str(t_flags *f, size_t mem_size, size_t len)
{
	if (f->left_adjusted)
		return (0);
	return (mem_size - len);
}

t_printable_mem	*create_str_to_print(char *s, t_flags *f, size_t len)
{
	t_printable_mem	*m;
	size_t			start;
	size_t			size;

	if (f->is_precision)
		len = get_smaller(len, f->precision_value);
	size = get_size_for_str(f, len);
	m = generic_create_mem(f, size);
	if (m)
	{
		start = get_start_for_str(f, size, len);
		ft_memcpy((m->mem + start), s, len);
	}
	return (m);
}

t_printable_mem	*convert_str(va_list l, t_flags *f)
{
	char	*s;

	s = va_arg(l, char *);
	if (!s)
		s = NULL_STR;
	f->pad = ' ';
	return (create_str_to_print(s, f, ft_strlen(s)));
}
