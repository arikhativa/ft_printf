/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 14:50:32 by yoav              #+#    #+#             */
/*   Updated: 2022/06/20 11:19:37 by yoav             ###   ########.fr       */
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
		convert_char(l, content, flags);
	else if ('s' == flags->conversion)
		convert_str(l, content, flags);
	else if ('d' == flags->conversion)
		convert_dec(l, content, flags);
	else if ('x' == flags->conversion)
		convert_hax_lower(l, content, flags);
	else if ('X' == flags->conversion)
		convert_hax_upper(l, content, flags);
	else if ('i' == flags->conversion)
		convert_dec(l, content, flags);
	else if ('u' == flags->conversion)
		convert_unsigned_dec(l, content, flags);
	else if ('p' == flags->conversion)
		convert_ptr(l, content, flags);
}

int	get_input_data(const char **str, va_list l, void **content, size_t *len)
{
	int			stt;
	const char	*s;
	t_flags		flags;

	*content = NULL;
	s = ft_strchr_wrapper(*str, len);
	if (!s || !(*s) || *s != '%')
		stt = SUCCESS;
	else
	{
		if (*(++s))
		{
			s = get_all_flags(s, &flags);
			create_content(l, content, &flags);
			if (NULL == *content)
				stt = ERROR;
		}
	}
	*str = s;
	return (stt);
}
