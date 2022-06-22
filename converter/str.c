/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 12:39:34 by yoav              #+#    #+#             */
/*   Updated: 2022/06/22 12:31:33 by yoav             ###   ########.fr       */
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

static size_t	get_size_for_str(t_flags *f, size_t len)
{
	return (get_bigger(f->width, len));
}

t_printable_mem	*create_str_to_print(char *s, t_flags *f, size_t len)
{
	t_printable_mem	*m;
	size_t			start;
	size_t			size;

	size = get_size_for_str(f, len);
	m = generic_create_mem(f, size);
	if (m)
	{
		start = generic_get_start(f, size, len);
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
