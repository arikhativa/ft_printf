/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 12:39:34 by yoav              #+#    #+#             */
/*   Updated: 2022/06/19 14:18:26 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>

#include "libft.h"
#include "parser.h"
#include "converter.h"

void	create_str(char	*s, void **res, t_flags *f)
{
	int		len;
	int		size;
	int		start;
	char	*new;

	len = ft_strlen(s);
	new = generic_create_str(f, len);
	printf("X: \n");
	printf("A: %s\n", new);
	size = generic_get_size(f->width, len);
	if (*res)
	{
		start = generic_get_start(f, size, len);
		ft_strlcpy((new + start), s, len);
	}
	*res = (void *)new;
}

void	convert_str(va_list l, void **res, t_flags *f)
{
	char	*s;

	s = va_arg(l, char *);
	create_str(s, res, f);
}


