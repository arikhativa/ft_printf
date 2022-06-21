/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 12:39:34 by yoav              #+#    #+#             */
/*   Updated: 2022/06/21 09:53:32 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>

#include "libft.h"
#include "parser.h"
#include "generic.h"
#include "printable_mem.h"
#include "converter.h"

t_printable_mem *create_str_to_print(char *s, t_flags *f, size_t len)
{
	t_printable_mem *m;
	int				start;

	m = generic_create_mem(f, len);
	if (m)
	{
		start = generic_get_start(f, len);
		ft_memcpy((m->mem + start), s, len);
	}
	return (m);
}

t_printable_mem *convert_str(va_list l, t_flags *f)
{
	char	*s;

	s = va_arg(l, char *);
	if (!s)
		s = NULL_STR;
	f->pad = ' ';
	return (create_str_to_print(s, f, ft_strlen(s)));
}
