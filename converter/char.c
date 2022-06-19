/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 09:52:33 by yoav              #+#    #+#             */
/*   Updated: 2022/06/19 13:00:38 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>

#include "parser.h"

static int get_size(int w)
{
	if (w)
		return (w + 1);
	return (2);
}

void	create_char(va_list l, void **res, t_flags *flags)
{
}
