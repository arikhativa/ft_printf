/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 14:05:26 by yoav              #+#    #+#             */
/*   Updated: 2022/06/16 17:40:33 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stddef.h>
#include <stdarg.h>

#include "ft_param_metadata.h"
#include "ft_parser.h"
#include "ft_printf.h"
#include "ft_strings.h"
#include "libft.h"

void	free_node_content(void *data)
{
	free(data);
}

int	ft_printf(const char *s, ...)
{
	t_param_metadata	m;
	const char			*runner;
	va_list				list;
	size_t				len;
	t_list				*node;

	if (!s)
		return (ERROR);
	len = 0;
	va_start(list, s);
	runner = s;
	node = NULL;
	while (*runner)
	{
		runner = get_input_data(runner, list, &m, &len);
		add_param_to_list(&node, &m, &len);
	}
	print_all(s, node, len);
	ft_lstclear(&node, free_node_content);
	va_end(list);
	return (0);
}
