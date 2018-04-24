/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wchartostr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/31 12:59:07 by tcharrie          #+#    #+#             */
/*   Updated: 2018/01/02 12:44:24 by tcharrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_lenchar(int c)
{
	int	i;

	i = 1;
	while ((c /= 2))
		i++;
	if (i <= 7)
		return (1);
	if (i <= 11)
		return (2);
	if (i <= 16)
		return (3);
	if (i <= 21)
		return (4);
	return (0);
}

static void	ft_wcharinchar(char *str, wchar_t c)
{
	int		i;

	i = ft_lenchar(c);
	if (i == 1)
		*str = c & 0x7f;
	if (i == 2)
	{
		str[0] = ((c / 64) & 0xdf) | 0xc0;
		str[1] = ((c % 64) & 0xbf) | 0x80;
	}
	if (i == 3)
	{
		str[0] = ((c / 4096) & 0xef) | 0xe0;
		str[1] = (((c / 64) % 64) & 0xbf) | 0x80;
		str[2] = ((c % 64) & 0xbf) | 0x80;
	}
	if (i == 4)
	{
		str[0] = ((c / 262144) & 0xf7) | 0xf0;
		str[1] = (((c / 4096) % 64) & 0xbf) | 0x80;
		str[2] = (((c / 64) % 64) & 0xbf) | 0x80;
		str[3] = ((c % 64) & 0xbf) | 0x80;
	}
}

char		*ft_wchartostr(wchar_t *src)
{
	char	*str;
	int		i[2];

	i[0] = 0;
	i[1] = 0;
	while (src && src[i[0]])
		i[1] += ft_lenchar(src[i[0]++]);
	if (!src || !(str = (char*)malloc(sizeof(char) * (i[1] + 1))))
		return (NULL);
	str[i[1]] = '\0';
	i[0] = 0;
	while (*src)
	{
		ft_wcharinchar(&str[i[0]], *src);
		i[0] += ft_lenchar(*src);
		src++;
	}
	return (str);
}
