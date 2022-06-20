/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 15:52:27 by yoav              #+#    #+#             */
/*   Updated: 2022/06/20 11:06:07 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "ft_printf.h"
#include "libft.h"

int	add_param_to_list(t_list **node, void *content, size_t *len)
{
	t_list	*new;

	if (content == NULL)
		return (SUCCESS);
	new = ft_lstnew(content);
	if (!new)
		return (ERROR);
	ft_lstadd_back(node, new);
	*len += ft_strlen((char *)content);
	return (SUCCESS);
}
