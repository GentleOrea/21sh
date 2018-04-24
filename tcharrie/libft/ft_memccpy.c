/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 15:35:35 by tcharrie          #+#    #+#             */
/*   Updated: 2017/11/18 11:36:38 by tcharrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (NULL);
	while (i < n &&
			(unsigned char)((char *)src)[i] !=
			(unsigned char)c)
	{
		((char*)dst)[i] = ((char *)src)[i];
		i++;
	}
	if ((unsigned char)((char *)src)[i] == (unsigned char)c && i < n)
	{
		((char *)dst)[i] = ((char *)src)[i];
		return ((void *)&(((char *)dst)[i + 1]));
	}
	return (NULL);
}
