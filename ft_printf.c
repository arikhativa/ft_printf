/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 14:05:26 by yoav              #+#    #+#             */
/*   Updated: 2022/06/16 14:31:32 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <stdarg.h>

int	ft_printf(const char *s, ...)
{
	char	*runner;

	if (!s)
		return (ERROR);
	runner = s;
	while (runner)
	{
		runner = ft_strchar(SEP);
	}
	// while s
		// get next %
		// create new str
	// malloc big str
	// cpy
	// print
}
