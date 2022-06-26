/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_flag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 16:45:05 by yoav              #+#    #+#             */
/*   Updated: 2022/06/26 18:04:49 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "flag.h"
#include "define.h"

static int	check_field(char type, char input, char *filed)
{
	if (type == input)
	{
		if (*filed)
			return (TRUE);
		else
			*filed = TRUE;
	}
	return (FALSE);
}

static int	is_duplicate(t_flag *f, char c)
{
	if (check_field(' ', c, &(f->space)))
		return (TRUE);
	if (check_field('0', c, &(f->pad)))
		return (TRUE);
	if (check_field('#', c, &(f->hash)))
		return (TRUE);
	if (check_field('-', c, &(f->left_adjusted)))
		return (TRUE);
	if (check_field('+', c, &(f->plus)))
		return (TRUE);
	return (FALSE);
}

int	is_flag_valid(const char *s)
{
	t_flag	f;

	ft_bzero(&f, sizeof(t_flag));
	if (!s || !*(s + 1))
		return (FALSE);
	++s;
	while (ft_strchr(ALL_FLAGS, *s))
	{
		if (is_duplicate(&f, *s))
			return (FALSE);
		++s;
	}
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
