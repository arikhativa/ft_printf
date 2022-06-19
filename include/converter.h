/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 10:01:54 by yoav              #+#    #+#             */
/*   Updated: 2022/06/19 13:29:48 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERTER_H
# define CONVERTER_H

# define PADDING ' '

#include <stdarg.h>

#include "parser.h"

void	convert_char(va_list l, void **res, t_flags *f);
void	convert_dec(va_list l, void **res, t_flags *f);
void	convert_str(va_list l, void **res, t_flags *f);
void	create_str(char	*s, void **res, t_flags *f);

#endif