/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 09:52:33 by yoav              #+#    #+#             */
/*   Updated: 2022/06/20 15:16:08 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>

#include "flags.h"
#include "converter.h"
#include "printable_mem.h"

t_printable_mem *convert_char(va_list l, t_flags *f)
{
	char	s[2];

	s[0] = va_arg(l, int);
	s[1] = '\0';
	return (create_str_to_print(s, f, 1));
}
