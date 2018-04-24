/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 17:01:12 by tcharrie          #+#    #+#             */
/*   Updated: 2017/11/18 12:08:34 by tcharrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	d;
	size_t	s;
	size_t	i;

	d = ft_strlen(dst);
	i = d;
	s = 0;
	if (size == 0)
		return (ft_strlen(src));
	while (src[s] && i + 1 < size)
		dst[i++] = src[s++];
	dst[i] = '\0';
	return (ft_strlen(src) + (size < d ? size : d));
}
