/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 10:23:02 by yoav              #+#    #+#             */
/*   Updated: 2022/06/15 13:48:58 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

static void	ft_byte_cpy(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*d;
	const char	*s;

	s = (char *)src;
	d = (char *)dest;
	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		++i;
	}
}

static void	ft_sizet_cpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	size_t			*d;
	const size_t	*s;

	s = (size_t *)src;
	d = (size_t *)dest;
	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		i += sizeof(size_t);
	}
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	bytes;

	if (!dest || !src)
		return (NULL);
	bytes = n % sizeof(size_t);
	n = n / sizeof(size_t);
	if (n)
		ft_sizet_cpy(dest, src, n);
	if (bytes)
		ft_byte_cpy(((size_t *)dest) + n, ((size_t *)src) + n, bytes);
	return (dest);
}
