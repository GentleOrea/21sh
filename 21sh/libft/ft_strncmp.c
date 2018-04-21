/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 17:41:43 by tcharrie          #+#    #+#             */
/*   Updated: 2018/02/09 11:09:41 by tcharrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (!s1 || !s2)
		return (0);
	i = 0;
	while (i < n && (unsigned char)(*s1) &&
			(unsigned char)(*s1) == (unsigned char)(*s2))
	{
		s1++;
		s2++;
		i++;
	}
	if (i == n)
		return (0);
	return ((unsigned char)(*s1) - (unsigned char)(*s2));
}
