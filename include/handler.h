/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hundler.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 16:10:20 by yoav              #+#    #+#             */
/*   Updated: 2022/06/23 16:11:57 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUNDLER_H
# define HUNDLER_H

# include <stdarg.h>

# include "printable_mem.h"
# include "flag.h"

# define NULL_STR	"(null)"
# define NIL_STR	"(nil)"

t_printable_mem	*convert_char(va_list l, t_flag *f);
t_printable_mem	*convert_dec(va_list l, t_flag *f);
t_printable_mem	*convert_unsigned_dec(va_list l, t_flag *f);
t_printable_mem	*convert_str(va_list l, t_flag *f);
t_printable_mem	*convert_ptr(va_list l, t_flag *f);
t_printable_mem	*convert_hax_upper(va_list l, t_flag *f);
t_printable_mem	*convert_hax_lower(va_list l, t_flag *f);

#endif