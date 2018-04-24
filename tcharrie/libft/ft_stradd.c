/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stradd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/27 14:42:01 by tcharrie          #+#    #+#             */
/*   Updated: 2017/12/27 14:42:02 by tcharrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_stradd(char *s1, char c)
{
	char	*s;
	int		i;

	if (!s1)
		return (NULL);
	if (!(s = (char*)malloc(ft_strlen(s1) + 2)))
	{
		free(s1);
		return (NULL);
	}
	i = -1;
	while (s1[++i])
		s[i] = s1[i];
	s[i++] = c;
	s[i] = '\0';
	ft_strdel(&s1);
	return (s);
}
