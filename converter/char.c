/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 09:52:33 by yoav              #+#    #+#             */
/*   Updated: 2022/06/20 12:02:15 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>

#include "converter.h"

void	convert_char(va_list l, void **res, t_flags *f, size_t *len)
{
	char	s[2];

	s[0] = va_arg(l, int);
	s[1] = '\0';
	*len += 1;
	create_str(s, res, f, 1);
}
