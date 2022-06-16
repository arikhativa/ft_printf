/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 15:52:27 by yoav              #+#    #+#             */
/*   Updated: 2022/06/16 16:06:34 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"
#include "ft_param_metadata.h"

static void	*create_char(char ch)
{
	char	*ret;
	ret = (char *)malloc(sizeof(char) * 2);
	if (ret)
	{
		ret[0] = ch;
		ret[1] = '\0';
	}
	return (ret);
}

void	add_param_to_list(t_list **node, t_param_metadata *m)
{
	t_list	*new;
	void	*value;
	
	if (m->type == 'c')
	{
		value = create_char(m->ch);
		if (!value)
			return ; // TODO
	}
	if (m->type == 'd')
	{
		value = (void *)ft_itoa(m->dec);
		if (!value)
			return ; // TODO
	}
	new = ft_lstnew(value);
	if (!new)
		return ; // TODO
	ft_lstadd_back(node, new);
}
