/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 16:13:38 by yoav              #+#    #+#             */
/*   Updated: 2022/06/21 09:26:25 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

#include "parser.h"
#include "ft_printf.h"
#include "libft.h"
#include "printable_mem.h"

static void	cpy_from_input(char **dest, const char **input)
{
	const char	*s;
	char		*d;
	int			i;

	s = *input;
	d = *dest;
	i = 0;
	while (s[i])
	{
		if (is_sep(s + i))
			break ;
		if (is_escp(s + i))
			++s;
		d[i] = s[i];
		++i;
	}
	*dest = (d + i);
	*input = skip_special_char(s + i);
}

static void	cpy_from_list(char **dest, t_list **list)
{
	int		i;

	if (!*list)
		return ;
	i = cpy_printable_mem(*dest, (*list)->content);
	*list = (*list)->next;
	*dest = (*dest + i);
}

static char	*create_string(const char *input, t_list *list, size_t len)
{
	char	*ret;
	char	*runner;

	ret = (char *)malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (NULL);
	ret[len] = '\0';
	runner = ret;
	while (*input)
	{
		cpy_from_input(&runner, &input);
		cpy_from_list(&runner, &list);
	}
	return (ret);
}

int	print_all(char *input, t_list *list)
{
	char	*s;
	size_t	len;

	len = count_normal_char_len(input);
	len += count_all_printable_mem_len(list);

	s = create_string(input, list, len);
	if (!s)
		return (ERROR);
	write(1, s, len);
	free(s);
	return (len);
}
