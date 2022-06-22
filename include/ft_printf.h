/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 19:38:03 by yoav              #+#    #+#             */
/*   Updated: 2022/06/22 09:35:16 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define ERROR		-1
# define SUCCESS	0
# define TRUE		1
# define FALSE		!TRUE

int	ft_printf(const char *s, ...) __attribute__((format(printf,1,2)));

#endif
