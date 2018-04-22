/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 15:50:54 by tcharrie          #+#    #+#             */
/*   Updated: 2017/11/14 14:29:48 by tcharrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_overlap(void *dst, const void *src, size_t len)
{
	while (len--)
	{
		if (src == dst)
			return (1);
		src++;
	}
	return (0);
}

void		*ft_memmove(void *dst, const void *src, size_t len)
{
	if (ft_overlap(dst, src, len))
	{
		src = src + len;
		dst = dst + len;
		while (len--)
		{
			dst--;
			src--;
			*((unsigned char *)dst) = *((unsigned char *)src);
		}
	}
	else
		dst = ft_memcpy(dst, src, len);
	return (dst);
}
