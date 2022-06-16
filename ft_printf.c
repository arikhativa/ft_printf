/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 14:05:26 by yoav              #+#    #+#             */
/*   Updated: 2022/06/16 16:32:51 by yoav             ###   ########.fr       */
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
	while (node)
	{
		printf("B: %s\n", node->content);
		node = node->next;
	}
	print_all(s, node, len);
	va_end(list);
	return (0);
	
	// while s
		// get next %
		// create new str
	// malloc big str
	// cpy
	// print
}
