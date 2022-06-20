/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 16:13:38 by yoav              #+#    #+#             */
/*   Updated: 2022/06/20 08:06:36 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

#include "parser.h"
#include "ft_printf.h"
#include "libft.h"

static void	cpy_from_input(char **dest, const char **input)
{
	const char	*s;
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
	*input = skip_special_char(s + i);
}

static void	cpy_from_list(char **dest, t_list **list)
{
	char	*s;
	char	*d;
	int		i;

	if (!*list)
		return ;
	s = (*list)->content;
	d = *dest;
	i = 0;
	while (s[i])
	{
		d[i] = s[i];
		++i;
	}
	*list = (*list)->next;
	*dest = (d + i);
}

static char	*create_str_to_print(const char *input, t_list *list, size_t len)
{
	char	*ret;
	char	*runner;

	ret = (char *)malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (NULL); // TODO
	ret[len] = '\0';
	runner = ret;
	while (*input)
	{
		cpy_from_input(&runner, &input);
		cpy_from_list(&runner, &list);
	}
	return (ret);
}

void	print_all(char *input, t_list *list, size_t len)
{
	char	*s;
	
	s = create_str_to_print(input, list, len);
	if (s)
	{
		write(1, s, len);
		free(s);
	}
}
