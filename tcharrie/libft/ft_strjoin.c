/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 19:18:41 by tcharrie          #+#    #+#             */
/*   Updated: 2017/11/18 11:55:21 by tcharrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dst;
	size_t	t;
	size_t	i;

	if (!s1 || !s2)
		return (NULL);
	if (!(dst = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)
						+ 1))))
		return (NULL);
	t = 0;
	i = 0;
	while (s1 && s1[t])
	{
		dst[t] = s1[t];
		t++;
	}
	while (s2 && s2[i])
	{
		dst[t + i] = s2[i];
		i++;
	}
	dst[t + i] = '\0';
	return (dst);
}
