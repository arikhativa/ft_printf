/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 12:39:34 by yoav              #+#    #+#             */
/*   Updated: 2022/06/20 12:03:36 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>

#include "libft.h"
#include "parser.h"
#include "converter.h"

void	create_str(char	*s, void **res, t_flags *f, size_t len)
{
	int		start;
	char	*new;

	new = generic_create_str(f, len);
	if (new)
	{
		start = generic_get_start(f, len);
		ft_memcpy((new + start), s, len);
	}
	*res = (void *)new;
}

void	convert_str(va_list l, void **res, t_flags *f, size_t *len)
{
	char	*s;

	s = va_arg(l, char *);
	f->pad = ' ';
	*len += ft_strlen(s);
	create_str(s, res, f, *len);
}
