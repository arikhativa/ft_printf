/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generic.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 10:01:54 by yoav              #+#    #+#             */
/*   Updated: 2022/06/20 13:55:44 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GENERIC_H
# define GENERIC_H

# include <stdarg.h>
# include <stddef.h>

# include "flags.h"

int		generic_get_start(t_flags *f, int len);
char	*generic_create_str(t_flags *f, int len);
void	convert_generic_number(long nbr, void **res, t_flags *f, char *base);
void	convert_generic_unsigned_number(\
						unsigned long nbr, void **res, t_flags *f, char *base);

#endif