/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 14:47:03 by yoav              #+#    #+#             */
/*   Updated: 2022/06/19 11:15:25 by yoav             ###   ########.fr       */
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

const char		*get_input_data(const char *s, va_list l, void **content, size_t *len);
const char	*skip_special_char(const char *s);

#endif