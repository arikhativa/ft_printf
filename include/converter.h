/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 10:01:54 by yoav              #+#    #+#             */
/*   Updated: 2022/06/20 14:00:02 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERTER_H
# define CONVERTER_H

# include <stdarg.h>
# include <stddef.h>

# include "flags.h"

void	convert_char(va_list l, void **res, t_flags *f, size_t *len);
void	convert_dec(va_list l, void **res, t_flags *f, size_t *len);
void	convert_unsigned_dec(va_list l, void **res, t_flags *f, size_t *len);
void	convert_str(va_list l, void **res, t_flags *f, size_t *len);
void	convert_ptr(va_list l, void **res, t_flags *f, size_t *len);
void	convert_hax_upper(va_list l, void **res, t_flags *f, size_t *len);
void	convert_hax_lower(va_list l, void **res, t_flags *f, size_t *len);

void	create_str(char	*s, void **res, t_flags *f, size_t len);
void	itoa_base(long n, char *base_str, char *ret, int digit);
void	stoa_base(size_t n, char *base_str, char *ret, size_t digit);

#endif