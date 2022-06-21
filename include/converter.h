/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 10:01:54 by yoav              #+#    #+#             */
/*   Updated: 2022/06/21 14:03:22 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERTER_H
# define CONVERTER_H

# include <stdarg.h>
# include <stddef.h>

# include "flags.h"
# include "printable_mem.h"

# define NULL_STR	"(null)"
# define NIL_STR	"(nil)"

t_printable_mem	*convert_char(va_list l, t_flags *f);
t_printable_mem	*convert_dec(va_list l, t_flags *f);
t_printable_mem	*convert_unsigned_dec(va_list l, t_flags *f);
t_printable_mem	*convert_str(va_list l, t_flags *f);
t_printable_mem	*convert_ptr(va_list l, t_flags *f);
t_printable_mem	*convert_hax_upper(va_list l, t_flags *f);
t_printable_mem	*convert_hax_lower(va_list l, t_flags *f);

t_printable_mem	*create_str_to_print(char *s, t_flags *f, size_t len);
void			itoa_base(long n, char *base_str, char *ret, int digit);
void			stoa_base(size_t n, char *base_str, char *ret, size_t digit);

#endif