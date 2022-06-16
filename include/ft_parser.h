/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 14:47:03 by yoav              #+#    #+#             */
/*   Updated: 2022/06/16 17:14:41 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PARSER_H
# define FT_PARSER_H

#include <stddef.h>
#include <stdarg.h>

#include "ft_param_metadata.h"

char		*get_input_data(const char *s, va_list l, t_param_metadata *m, size_t *len);
const char	*skip_special_char(const char *s);

#endif