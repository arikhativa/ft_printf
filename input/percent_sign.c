/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent_sign.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 09:04:31 by yoav              #+#    #+#             */
/*   Updated: 2022/06/26 18:11:35 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "define.h"
#include "input.h"
#include "flag.h"

int	is_escp(const char *s)
{
	if (!s || !*s)
		return (FALSE);
	if (*s == SEP_CHAR && *(s + 1) == SEP_CHAR)
		return (TRUE);
	return (FALSE);
}

int	is_flag(const char *s)
{
	if (!s || !*s)
		return (FALSE);
	if (*s == SEP_CHAR && is_flag_valid(s))
		return (TRUE);
	return (FALSE);
}
