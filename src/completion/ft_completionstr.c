/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_completionstr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 15:18:16 by tcharrie          #+#    #+#             */
/*   Updated: 2018/05/17 15:55:23 by tcharrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static char	*ft_straddsep_(char *str, char *split, int sep, int i, int j)
{
	while (sep && str[i])
	{
		if (str[i] == '\\' && sep != '\'')
		{
			split[j++] = '\\';
			split[j++] = '\\';
		}
		if (str[i] == sep)
		{
			split[j++] = sep;
			split[j++] = '\\';
			split[j++] = sep;
			sep = 0;
		}
		else
			split[j++] = str[i];
		i++;
	}
	while (str[i])
	{
		if (ft_isin(str[i], SPECIALCHAR))
			split[j++] = '\\';
		split[j++] = str[i++];
	}
	return (split);
}

char		*ft_straddsep(char *str, int bl, int sep)
{
	char	*split;
	int		i;
	int		j;

	if (!str)
		return (0);
	if (!(split = (char*)ft_memalloc(2 * ft_strlen(str) + 3)))
		return (0);
	i = 0;
	j = 0;
	if (bl)
		split[j++] = str[i++];
	return (ft_straddsep_(str, split, sep, i, j));
}

char		*ft_strpurgesep(char *str)
{
	int		i;
	char	*purged;
	int		j;
	int		sep[2];
	int		bl;

	if (!str)
		return (0);
	if (!(purged = (char*)ft_memalloc(ft_strlen(str) + 1)))
		return (0);
	i = 0;
	j = 0;
	bl = 0;
	ft_bzero((void*)sep, sizeof(sep));
	while (str[i])
	{
		sep[1] = ft_separator(str[i], sep[0], bl);
		bl = (str[i] == '\\' && !bl && sep != '\'');
		if (sep[1] != sep[0] || bl)
			i++;
		else
			split[j++] = str[i++];
		sep[0] = sep[1];
	}
	return (split);
}
