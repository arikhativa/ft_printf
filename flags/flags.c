/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 10:46:08 by yoav              #+#    #+#             */
/*   Updated: 2022/06/20 14:22:38 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "flags.h"
#include "ft_printf.h"

static const char	*parse_flags(const char *s, t_flags *f)
{
	f->pad = ' ';
	while (ft_strchr(ALL_FLAGS, *s))
	{
		if (' ' == *s)
			f->space = TRUE;
		else if ('#' == *s)
			f->hash = TRUE;
		else if ('0' == *s)
			f->pad = '0';
		else if ('+' == *s)
			f->plus = TRUE;
		else if ('-' == *s)
			f->left_adjusted = TRUE;
		// else if ('.' == *s) // TODO
			// f->precision = TRUE;
		++s;
	}
	if (f->left_adjusted)
		f->pad = ' ';
	return (s);
}

static const char	*get_width(const char *s, t_flags *f)
{
	f->width = ft_atoi(s);
	while (ft_isdigit(*s))
		++s;
	return (s);
}

static const char	*get_conversion(const char *s, t_flags *f)
{
	f->conversion = *s;
	return (s + 1);
}

const char	*get_flags(const char *s, t_flags *f)
{
	ft_bzero(f, sizeof(t_flags));
	s = parse_flags(s, f);
	s = get_width(s, f);
	s = get_conversion(s, f);
	return (s);
}
