/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 14:50:32 by yoav              #+#    #+#             */
/*   Updated: 2022/06/19 10:17:10 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdarg.h>

#include "setters.h"
#include "libft.h"
#include "ft_printf.h"
#include "ft_param_metadata.h"

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
	char *all_chars = "cd";

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

static void	create_content(int s, va_list l, void **content)
{
	if ('c' == s)
		set_char(l, content);
	else if ('d' == s)
		set_dec(l, content);
}

const char	*get_input_data(const char *s, va_list l, void **content, size_t *len)
{
	*content = NULL;
	s = ft_strchr_wrapper(s, len);
	if (!s || !(*s) || *s != '%')
		return (s);
	++s;
	if (!*s)
		return (s);
	create_content((int)*s, l, content);
	return (s + 1);
}
