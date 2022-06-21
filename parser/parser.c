/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 14:50:32 by yoav              #+#    #+#             */
/*   Updated: 2022/06/21 14:04:42 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdarg.h>

#include "libft.h"
#include "ft_printf.h"
#include "converter.h"
#include "flags.h"
#include "list.h"
#include "parser.h"

static int	is_convert_char(char c)
{
	return (ft_strchr(CONVERT_STR, c) != NULL);
}

const char	*skip_special_char(const char *s)
{
	while (*s && !is_convert_char(*s))
		++s;
	if (!*s)
		return (s);
	return (s + 1);
}

const char	*skip_normal_str(const char *s)
{
	while (*s && !is_sep(s))
	{
		if (is_escp(s))
			++s;
		++s;
	}
	if (is_sep(s))
		++s;
	return (s);
}

size_t	count_normal_char_len(const char *s)
{
	size_t	c;

	c = 0;
	while (*s)
	{
		if (is_sep(s))
			s = skip_special_char(s);
		else if (is_escp(s))
		{
			s += 2;
			++c;
		}
		else
		{
			++s;
			++c;
		}
	}
	return (c);
}

int	parse_input(const char *input, t_list **node, va_list list)
{
	t_flags			flags;
	t_printable_mem	*m;

	m = NULL;
	input = skip_normal_str(input);
	while (*input)
	{
		input = get_flags(input, &flags);
		m = create_printable_mem(list, &flags);
		if (NULL == m)
			return (ERROR);
		if (add_param_to_list(node, m) == ERROR)
			return (ERROR);
		input = skip_normal_str(input);
	}
	return (SUCCESS);
}
