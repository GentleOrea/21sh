/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 09:21:06 by ygarrot           #+#    #+#             */
/*   Updated: 2018/04/16 18:39:21 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

static int		countletters(char const *s, char c)
{
	int cl;
	int		q[2];

	cl = 0;
	while (s[cl] != c && s[cl] && !q[0] && !q[1])
	{
		if (q[0])
		cl++;
	}
	return (cl);
}

static int		countwords(char const *s, char c)
{
	int i;
	int i2;

	i = 0;
	i2 = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] && s[i] != c && ++i2)
			i += countletters(s, c);
	}
	return (i2);
}

static char		**cpy(char const *s, char c, char **fresh, int words)
{
	int		i;
	int		i3;

	i = -1;
	while (++i < words)
	{
		i3 = 0;
		while (*s && *s == c)
			s++;
		if (!(fresh[i] = ft_strnew(i3 = countletters(s, c))))
		{
			ft_free_dblechar_tab(fresh);
			return (NULL);
		}
		while (i3)
			fresh[i][i3--] = *s++;
	}
	return (fresh);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**fresh;
	int		words;

	if (!(s && c))
		return (NULL);
	words = countwords(s, c);
	if (!(fresh = (char**)ft_memalloc((words + 1) * sizeof(char*))))
		return (NULL);
	return (cpy(s, c, fresh, words));
}
