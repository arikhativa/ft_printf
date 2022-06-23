/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 14:05:26 by yoav              #+#    #+#             */
/*   Updated: 2022/06/23 16:23:08 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdarg.h>
#include <stdlib.h>

#include "libft.h"
#include "ft_printf.h"
#include "list.h"
#include "input.h"
#include "printer.h"
#include "printable_mem.h"

int	ft_printf(const char *s, ...)
{
	va_list		list;
	t_list		*node;
	int			stt;

	if (!s)
		return (ERROR);
	va_start(list, s);
	node = NULL;
	stt = parse_input(s, &node, list);
	if (SUCCESS == stt)
		stt = print_all(s, node);
	ft_lstclear(&node, free_printable_mem);
	va_end(list);
	return (stt);
}
