/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 19:38:03 by yoav              #+#    #+#             */
/*   Updated: 2022/06/20 11:06:02 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define ERROR		-1
# define SUCCESS	0
# define SEP		'%'
# define TRUE		1

int		ft_printf(const char *s, ...);

#endif
