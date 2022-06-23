/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 11:14:33 by yoav              #+#    #+#             */
/*   Updated: 2022/06/22 11:20:32 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLAG_H
# define FLAG_H

# define ALL_FLAGS		"-0# +"

typedef struct s_flag
{
	size_t	precision_value;
	int		is_precision;
	int		is_upper;
	int		hash;
	int		space;
	int		plus;
	int		left_adjusted;
	int		width;
	char	conversion;
	char	pad;
}	t_flag;

const char	*parse_flag(const char *s, t_flag *f);
const char	*get_flag(const char *s, t_flag *f);

#endif