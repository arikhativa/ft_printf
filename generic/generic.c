/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 14:05:38 by yoav              #+#    #+#             */
/*   Updated: 2022/06/20 08:37:11 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"
#include "flags.h"

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

char	*generic_create_str(t_flags *f, int len)
{
	int		size;
	char	*ret;

	size = generic_get_size(f->width, len);
	ret = (char *)malloc(sizeof(char) * (size + 1));
	if (ret)
	{
		ft_memset(ret, f->pad, size);
		ret[size] = '\0';
	}
	return (ret);
}
