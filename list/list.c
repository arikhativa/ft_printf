/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 15:52:27 by yoav              #+#    #+#             */
/*   Updated: 2022/06/19 10:18:16 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"

void	add_param_to_list(t_list **node, void *content, size_t *len)
{
	t_list	*new;
	
	if (content == NULL)
		return ;
	new = ft_lstnew(content);
	if (!new)
		return ; // TODO
	ft_lstadd_back(node, new);
	*len += ft_strlen((char *)content);
}
