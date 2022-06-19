/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 12:39:34 by yoav              #+#    #+#             */
/*   Updated: 2022/06/19 13:29:56 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>

#include "libft.h"
#include "parser.h"
#include "converter.h"

static int get_size(int w, int l)
{
	if (w > l)
		return (w);
	return (l);
}

static int	get_start(t_flags *f, int size, int len)
{
	if (f->left_adjusted)
		return (0);
	return (size - len);
}

void	create_str(char	*s, void **res, t_flags *f)
{
	int		len;
	int		size;
	int		start;
	int		i;

	len = ft_strlen(s);
	size = get_size(f->width, len);
	*res = (char *)malloc(sizeof(char) * (size + 1));
	if (*res)
	{
		ft_memset(*res, PADDING, size);
		((char *)(*res))[size] = '\0';
		start = get_start(f, size, len);
		i = 0;
		while (i < (len))
		{
			((char *)(*res))[start + i] = s[i];
			++i;
		}
	}
}

void	convert_str(va_list l, void **res, t_flags *f)
{
	char	*s;

	s = va_arg(l, char *);
	create_str(s, res, f);
}


