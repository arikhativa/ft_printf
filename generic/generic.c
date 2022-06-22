/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 14:05:38 by yoav              #+#    #+#             */
/*   Updated: 2022/06/22 12:36:55 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"
#include "flags.h"
#include "printable_mem.h"

size_t	get_bigger(size_t a, size_t b)
{
	if (a > b)
		return (a);
	return (b);
}

size_t	generic_get_start(t_flags *f, size_t mem_size, size_t value_len)
{
	if (f->left_adjusted)
		return (0);
	value_len = get_bigger(f->precision_value, value_len);
	return (mem_size - value_len);
}

t_printable_mem	*generic_create_mem(t_flags *f, size_t size) // TODO move?
{
	t_printable_mem	*ret;

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
