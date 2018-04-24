/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 19:26:23 by tcharrie          #+#    #+#             */
/*   Updated: 2017/11/18 11:47:14 by tcharrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_mem(char const *s)
{
	size_t	t;
	size_t	i;

	t = 0;
	while (s[t] == ' ' || s[t] == '\n' || s[t] == '\t')
		t++;
	i = ft_strlen(s);
	if (i == t)
		return (0);
	if (i > 0 && i != t)
	{
		i--;
		while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
			i--;
	}
	return (i + 1 - t);
}

char		*ft_strtrim(char const *s)
{
	char	*dst;
	int		t;

	if (!s)
		return (NULL);
	t = ft_mem(s);
	if (!(dst = (char *)malloc(sizeof(char) * ((size_t)t + 1))))
		return (NULL);
	dst[t] = '\0';
	while (*s == ' ' || *s == '\t' || *s == '\n')
		s++;
	while (--t >= 0)
		dst[t] = s[t];
	return (dst);
}
