/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 18:58:19 by tcharrie          #+#    #+#             */
/*   Updated: 2017/11/18 11:42:23 by tcharrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*dst;
	unsigned int	n;

	if (!f || !(dst = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1))))
		return (NULL);
	n = 0;
	while (s && s[n])
	{
		dst[n] = f(n, s[n]);
		n++;
	}
	if (s)
		dst[n] = '\0';
	return (dst);
}
