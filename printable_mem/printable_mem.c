/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printable_mem.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 14:25:16 by yoav              #+#    #+#             */
/*   Updated: 2022/06/20 15:47:46 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>

#include "libft.h"
#include "flags.h"
#include "converter.h"
#include "printable_mem.h"

t_printable_mem *create_printable_mem(va_list l, t_flags *flags)
{
	if ('c' == flags->conversion)
		return (convert_char(l, flags));
	else if ('s' == flags->conversion)
		return (convert_str(l, flags));
	else if ('d' == flags->conversion)
		return (convert_dec(l, flags));
	else if ('x' == flags->conversion)
		return (convert_hax_lower(l, flags));
	else if ('X' == flags->conversion)
		return (convert_hax_upper(l, flags));
	else if ('i' == flags->conversion)
		return (convert_dec(l, flags));
	else if ('u' == flags->conversion)
		return (convert_unsigned_dec(l, flags));
	else if ('p' == flags->conversion)
		return (convert_ptr(l, flags));
	return (NULL);
}

size_t	cpy_printable_mem(char *d, t_printable_mem *m)
{
	size_t	i;

	if (!m)
		return (0);
	i = 0;
	while (i < m->size)
	{
		d[i] = m->mem[i];
		++i;
	}
	return (i);
}

void	free_printable_mem(void *content)
{
	t_printable_mem *m;

	m = (t_printable_mem *)content;
	free(m->mem);
	m->mem = NULL;
	m->size = 0;
	free(m);
}

size_t	count_all_printable_mem_len(t_list *list)
{
	t_printable_mem *m;
	size_t			c;

	c = 0;
	while (list)
	{
		m = list->content;
		c += m->size;
		list = list->next;
	}
}
