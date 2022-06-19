/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 10:01:54 by yoav              #+#    #+#             */
/*   Updated: 2022/06/19 16:28:47 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERTER_H
# define CONVERTER_H

#include <stdarg.h>
#include <stddef.h>

#include "flags.h"

void	convert_char(va_list l, void **res, t_flags *f);
void	convert_dec(va_list l, void **res, t_flags *f);
void	convert_str(va_list l, void **res, t_flags *f);
void	create_str(char	*s, void **res, t_flags *f);

long	count_digit_by_base(long n, long base);
void	itoa_base(long n, char *base_str, char *ret, int digit);

int		generic_get_start(t_flags *f, int len);
char	*generic_create_str(t_flags *f, int len);

void	convert_generic_number(long nbr, void **res, t_flags *f, char *base);
void	convert_generic_unsigned_number(unsigned long nbr, void **res, t_flags *f, char *base);

void	convert_hax_upper(va_list l, void **res, t_flags *f);
void	convert_hax_lower(va_list l, void **res, t_flags *f);

void	stoa_base(size_t n, char *base_str, char *ret, size_t digit);
long	count_digit_by_base_unsigned(size_t n, long base);

#endif