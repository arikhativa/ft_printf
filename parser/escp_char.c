/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   escp_char.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 09:04:31 by yoav              #+#    #+#             */
/*   Updated: 2022/06/21 09:35:46 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "parser.h"

int	is_escp(const char *s)
{
	if (!s || !*s)
		return (FALSE);
	if (*s == SEP_CHAR && *(s + 1) == SEP_CHAR)
		return (TRUE);
	return (FALSE);
}

int	is_sep(const char *s)
{
	if (!s || !*s)
		return (FALSE);
	if (*s == SEP_CHAR && *(s + 1) != SEP_CHAR)
		return (TRUE);
	return (FALSE);
}
