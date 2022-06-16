/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_param_metadata.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 14:51:52 by yoav              #+#    #+#             */
/*   Updated: 2022/06/16 15:24:16 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PARAM_METADATA_H
# define FT_PARAM_METADATA_H

typedef struct s_param_metadata
{
	int		size;
	char	type;
	void	*ptr;
	int		ch;
	int		dec;
}	t_param_metadata;

#endif