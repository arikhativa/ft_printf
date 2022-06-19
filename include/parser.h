/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 14:47:03 by yoav              #+#    #+#             */
/*   Updated: 2022/06/19 11:36:26 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

#include <stddef.h>
#include <stdarg.h>

#define ALL_FLAGS	"-0.# +"

typedef struct	s_flags
{
	int		hash;
	int		space;
	int		plus;
	int		zero;
	int		left_adjusted;
	int		precision;
	int		width;
	char	conversion;
}	t_flags;

// TODO remove
// printf("f: \nhash: %d\nspace: %d\nplus: %d\nzero: %d\nleft_adjusted: %d\nprecision: %d\nwidth: %d\nconversion: %c\n",\
				f->hash, f->space, f->plus, f->zero, f->left_adjusted,f->precision, f->width, f->conversion);


const char		*get_input_data(const char *s, va_list l, void **content, size_t *len);
const char	*skip_special_char(const char *s);

#endif