/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 14:05:26 by yoav              #+#    #+#             */
/*   Updated: 2022/06/20 11:18:40 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdarg.h>
#include <stdlib.h>

#include "libft.h"
#include "ft_printf.h"
#include "list.h"
#include "parser.h"
#include "printer.h"

void	free_node_content(void *data)
{
	free(data);
}

static int	parse_all_input(const char *input, t_list **node, va_list list, \
	size_t *len)
{
	void	*content;

	while (*input)
	{
		if (get_input_data(&input, list, &content, len) == ERROR)
			return (ERROR);
		if (add_param_to_list(node, content, len) == ERROR)
			return (ERROR);
	}
	return (SUCCESS);
}

int	ft_printf(const char *s, ...)
{
	va_list		list;
	size_t		len;
	t_list		*node;
	int			stt;

	if (!s)
		return (ERROR);
	len = 0;
	va_start(list, s);
	node = NULL;
	if (parse_all_input(s, &node, list, &len))
		stt = print_all(s, node, len);
	ft_lstclear(&node, free_node_content);
	va_end(list);
	return (stt);
}
