/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 18:30:54 by tcharrie          #+#    #+#             */
/*   Updated: 2017/11/08 18:46:29 by tcharrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*dst;

	if (!(dst = malloc(sizeof(char) * (size + 1))))
		return (NULL);
	while (size > 0)
	{
		dst[size] = (char)'\0';
		size--;
	}
	dst[0] = (char)'\0';
	return (dst);
}
