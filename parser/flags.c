/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 10:46:08 by yoav              #+#    #+#             */
/*   Updated: 2022/06/19 11:36:57 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "ft_printf.h"

const char	*get_flag(const char *s, t_flags *f)
{
	while (ft_strchr(ALL_FLAGS, *s))
	{
		if (' ' == *s)
			f->space = TRUE;
		else if ('#' == *s)
			f->hash = TRUE;
		else if ('0' == *s)
			f->zero = TRUE;
		else if ('+' == *s)
			f->plus = TRUE;
		else if ('-' == *s)
			f->left_adjusted = TRUE;
		// else if ('.' == *s) // TODO
			// f->precision = TRUE;
		++s;
	}
	return (s);
}

const char	*get_width(const char *s, t_flags *f)
{
	f->width = ft_atoi(s);
	while (ft_isdigit(*s))
		++s;
	return (s);
}

const char	*get_conversion(const char *s, t_flags *f)
{
	f->conversion = *s;
	return (s + 1);
}

const char	*get_all_flags(const char *s, t_flags *f)
{
	ft_bzero(f, sizeof(t_flags));
	s = get_flag(s, f);
	s = get_width(s, f);
	s = get_conversion(s, f);
	return (s);
}