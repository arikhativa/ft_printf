/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 10:01:54 by yoav              #+#    #+#             */
/*   Updated: 2022/06/19 13:20:35 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERTER_H
# define CONVERTER_H

# define PADDING ' '

#include <stdarg.h>

#include "parser.h"

void	create_char(va_list l, void **res, t_flags *flags);
void	create_dec(va_list l, void **res, t_flags *flags);
void	create_str(va_list l, void **res, t_flags *f);

#endif