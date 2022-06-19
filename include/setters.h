/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setters.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 10:01:54 by yoav              #+#    #+#             */
/*   Updated: 2022/06/19 10:41:57 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SETTERS_H
# define SETTERS_H

#include <stdarg.h>

#include "parser.h"

void	*set_char(va_list l, void **res, t_flags *flags);
void	*set_dec(va_list l, void **res, t_flags *flags);

#endif