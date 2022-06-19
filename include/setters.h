/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setters.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 10:01:54 by yoav              #+#    #+#             */
/*   Updated: 2022/06/19 10:16:32 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SETTERS_H
# define SETTERS_H

#include <stdarg.h>

void	*set_char(va_list l, void **res);
void	*set_dec(va_list l, void **res);

#endif