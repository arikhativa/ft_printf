/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 11:14:33 by yoav              #+#    #+#             */
/*   Updated: 2022/06/19 16:07:48 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLAGS_H
# define FLAGS_H

#define ALL_FLAGS	"-0.# +"

typedef struct	s_flags
{
	int		hash;
	int		space;
	int		plus;
	int		left_adjusted;
	int		width;
	int		precision;
	char	conversion;
	char	pad;
}	t_flags;

const char	*get_all_flags(const char *s, t_flags *f);

#endif