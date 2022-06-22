/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generic.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 10:01:54 by yoav              #+#    #+#             */
/*   Updated: 2022/06/22 12:35:26 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GENERIC_H
# define GENERIC_H

# include <stdarg.h>
# include <stddef.h>

# include "flags.h"
# include "printable_mem.h"

size_t	get_bigger(size_t a, size_t b);
size_t			generic_get_start(t_flags *f, size_t mem_size, \
									size_t value_len);
t_printable_mem	*generic_create_mem(t_flags *f, size_t size);
t_printable_mem	*convert_generic_number(long nbr, t_flags *f, char *base);
t_printable_mem	*convert_generic_unsigned_number(size_t nbr, t_flags *f, \
					char *base);

#endif