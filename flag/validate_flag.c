/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_flag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 16:45:05 by yoav              #+#    #+#             */
/*   Updated: 2022/06/23 17:00:03 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "flag.h"
#include "define.h"

int	is_flag_valid(const char *s)
{
	if (!s || *s)
		return (FALSE);
	while (ft_strchr(ALL_FLAGS, *s))
		++s;
	while (ft_isdigit(*s))
		++s;
	if (*s == '.')
	{
		++s;
		while (ft_isdigit(*s))
			++s;
	}
	return (is_handler_char(*s));
}
