/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.h                                        :+:      :+:    :+:   */
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

# include "flag.h"
# include "printable_mem.h"

t_printable_mem	*create_str_to_print(char *s, t_flag *f, size_t len);

void			itoa_base(long n, char *base_str, char *ret, int digit);
void			stoa_base(size_t n, char *base_str, char *ret, size_t digit);

#endif