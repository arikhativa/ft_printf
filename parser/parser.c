/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 14:50:32 by yoav              #+#    #+#             */
/*   Updated: 2022/06/20 15:48:46 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdarg.h>

#include "libft.h"
#include "ft_printf.h"
#include "converter.h"
#include "flags.h"
#include "list.h"

static int	is_special_char(char c)
{
	char *all_chars = "cspdiuxX"; // TODO not sure about %

	return (ft_strchr(all_chars, c) != NULL);
}

const char	*skip_special_char(const char *s)
{
	while (*s && !is_special_char(*s))
		++s;
	if (!*s)
		return (s);
	return (s + 1);
}

const char	*skip_normal_str(const char *s)
{
	while (*s && *s != SEP)
		++s;
	if (*s == SEP)
		++s;
	return (s);
}

size_t	count_normal_char_len(const char *s)
{
	size_t	c;

	c = 0;
	while (*s)
	{
		if (*s == SEP)
			s = skip_special_char(s);
		++c;
		++s;
	}
	return (c);
}

int	parse_input(const char *input, t_list **node, va_list list)
{
	t_flags	flags;
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
