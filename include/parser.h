/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 14:47:03 by yoav              #+#    #+#             */
/*   Updated: 2022/06/19 16:08:00 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

#include <stddef.h>
#include <stdarg.h>

// TODO remove
// printf("f: \nhash: %d\nspace: %d\nplus: %d\nzero: %d\nleft_adjusted: %d\nprecision: %d\nwidth: %d\nconversion: %c\n",\
				f->hash, f->space, f->plus, f->zero, f->left_adjusted,f->precision, f->width, f->conversion);


const char	*get_input_data(const char *s, va_list l, void **content, size_t *len);
const char	*skip_special_char(const char *s);

#endif