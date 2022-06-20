/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printable_mem.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 14:23:51 by yoav              #+#    #+#             */
/*   Updated: 2022/06/20 15:54:05 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTABLE_MEM_H
# define PRINTABLE_MEM_H

#include <stddef.h>
#include <stdarg.h>

#include "libft.h"
#include "flags.h"

typedef struct s_printable_mem
{
	char	*mem;
	size_t	size;
}	t_printable_mem;

size_t				cpy_printable_mem(char *d, t_printable_mem *m);
t_printable_mem	*create_printable_mem(va_list l, t_flags *flags);
void			free_printable_mem(void *content);
size_t			count_all_printable_mem_len(t_list *list);

#endif
