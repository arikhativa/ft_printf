/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 14:50:32 by yoav              #+#    #+#             */
/*   Updated: 2022/06/19 13:15:43 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdarg.h>

#include "libft.h"
#include "ft_printf.h"
#include "converter.h"
#include "flags.h"

static const char	*ft_strchr_wrapper(const char *s, size_t *len)
{
	const char	*tmp;

	tmp = s;
	while (*s && *s != SEP)
		++s;
	*len += (size_t)(s - tmp);
	return (s);
}

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

static void	create_content(va_list l, void **content, t_flags *flags)
{
	if ('c' == flags->conversion)
		create_char(l, content, flags);
	else if ('s' == flags->conversion)
		create_str(l, content, flags);
	else if ('d' == flags->conversion)
		create_dec(l, content, flags);
}

const char	*get_input_data(const char *s, va_list l, void **content, size_t *len)
{
	t_flags	flags;

	*content = NULL;
	s = ft_strchr_wrapper(s, len);
	if (!s || !(*s) || *s != '%')
		return (s);
	++s;
	if (!*s)
		return (s);
	s = get_all_flags(s, &flags);
	create_content(l, content, &flags);
	return (s);
}
