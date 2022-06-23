/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 09:52:33 by yoav              #+#    #+#             */
/*   Updated: 2022/06/23 16:17:01 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>

#include "flag.h"
#include "convert.h"
#include "printable_mem.h"

t_printable_mem	*convert_char(va_list l, t_flag *f)
{
	char	s[2];

	s[0] = va_arg(l, int);
	s[1] = '\0';
	return (create_str_to_print(s, f, 1));
}
