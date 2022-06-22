/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 14:05:38 by yoav              #+#    #+#             */
/*   Updated: 2022/06/22 10:12:12 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"
#include "flags.h"
#include "printable_mem.h"

static int	generic_get_size(int w, int l)
{
	if (w > l)
		return (w);
	return (l);
}

int	generic_get_start(t_flags *f, int len)
{
	int	size;

	size = generic_get_size(f->width, len);
	if (f->left_adjusted)
		return (0);
	return (size - len);
}

t_printable_mem	*generic_create_mem(t_flags *f, int len) // TODO move?
{
	int				size;
	t_printable_mem	*ret;

	size = generic_get_size(f->width, len);
	ret = (t_printable_mem *)malloc(sizeof(t_printable_mem));
	if (ret)
	{
		ret->mem = (char *)malloc(sizeof(char) * (size + 1));
		if (!ret->mem)
		{
			free(ret);
			return (NULL);
		}
		ft_memset(ret->mem, f->pad, size);
		ret->mem[size] = '\0';
		ret->size = size;
	}
	return (ret);
}
