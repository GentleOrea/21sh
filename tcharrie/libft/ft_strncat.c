/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 16:57:54 by tcharrie          #+#    #+#             */
/*   Updated: 2018/04/23 14:18:13 by tcharrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	t;
	size_t	i;

	if (!s2 || !s1)
		return (s1);
	i = 0;
	t = 0;
	while (s1[t])
		t++;
	while (s2[i] && i < n)
	{
		s1[t + i] = s2[i];
		i++;
	}
	s1[t + i] = '\0';
	return (s1);
}
