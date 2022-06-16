/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 14:50:32 by yoav              #+#    #+#             */
/*   Updated: 2022/06/16 17:45:41 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdarg.h>

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

const char	*get_input_data(const char *s, va_list l, t_param_metadata *m, size_t *len)
{
	m->type = ERROR;
	s = ft_strchr_wrapper(s, len);
	if (!s || !(*s) || *s != '%')
		return (s);
	++s;
	if (!*s)
		return (s);
	if (*s == 'c')
	{
		m->type = 'c';
		m->size = sizeof(int);
		m->ch = va_arg(l, int);
	} else if (*s == 'd')
	{
		m->type = 'd';
		m->size = sizeof(int);
		m->dec = va_arg(l, int);
	}
	return (s + 1);
}
