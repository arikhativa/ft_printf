/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 14:05:26 by yoav              #+#    #+#             */
/*   Updated: 2022/06/19 13:10:03 by yoav             ###   ########.fr       */
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

int	ft_printf(const char *s, ...)
{
	void		*content;
	const char	*runner;
	va_list		list;
	size_t		len;
	t_list		*node;

	if (!s)
		return (ERROR);
	len = 0;
	va_start(list, s);
	runner = s;
	node = NULL;
	while (*runner)
	{
		runner = get_input_data(runner, list, &content, &len);
		add_param_to_list(&node, content, &len);
	}
	print_all(s, node, len);
	ft_lstclear(&node, free_node_content);
	va_end(list);
	return (0);
}
