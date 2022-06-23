/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 14:00:11 by yoav              #+#    #+#             */
/*   Updated: 2022/06/23 16:39:56 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COUNT_H
# define COUNT_H

# include <stddef.h>

size_t	count_digit_by_base(long n, size_t base);
size_t	count_digit_by_base_unsigned(size_t n, size_t base);

#endif