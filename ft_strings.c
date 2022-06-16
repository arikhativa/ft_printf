/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strings.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 16:13:38 by yoav              #+#    #+#             */
/*   Updated: 2022/06/16 16:35:15 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "ft_printf.h"
#include "libft.h"

static void	cpy_from_input(char **dest, char **input)
{
	char	*s;
	char	*d;
	int		i;

	s = *input;
	d = *dest;
	i = 0;
	while (s[i] && s[i] != SEP)
	{
		d[i] = s[i];
		++i;
	}
	*dest = (d + i);
	*input = (s + i);
}

static char	*create_str_to_print(char *input, t_list *args, size_t len)
{
	char	*ret;
	char	*runner;

	ret = (char *)malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (NULL); // TODO
	runner = ret;
	while (*input)
	{
		cpy_from_input(&runner, &input);
	}
	return (ret);
}

int	print_all(char *input, t_list *args, size_t len)
{
	char	*s;
	
	s = create_str_to_print(input, args, len);
	if (!s)
		return (ERROR);
	write(1, s, len);
	free(s);
}