/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 10:01:54 by yoav              #+#    #+#             */
/*   Updated: 2022/06/19 14:16:58 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERTER_H
# define CONVERTER_H

# define PADDING ' '

#include <stdarg.h>

#include "flags.h"

void	convert_char(va_list l, void **res, t_flags *f);
void	convert_dec(va_list l, void **res, t_flags *f);
void	convert_str(va_list l, void **res, t_flags *f);
void	create_str(char	*s, void **res, t_flags *f);
void	itoa_base(int n, char *base_str, char *ret);

int		generic_get_start(t_flags *f, int size, int len);
int		generic_get_size(int w, int l);
char	*generic_create_str(t_flags *f, int len);


#endif