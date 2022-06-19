/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_char.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 09:52:33 by yoav              #+#    #+#             */
/*   Updated: 2022/06/19 10:09:29 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>

#include "ft_param_metadata.h"

static void	*create_char(char ch)
{
	char	*ret;
	ret = (char *)malloc(sizeof(char) * 2);
	if (ret)
	{
		ret[0] = ch;
		ret[1] = '\0';
	}
	return (ret);
}

void	set_char(va_list l, void **res)
{
	char c;

	c = va_arg(l, int);
	*res = create_char(c);
}
