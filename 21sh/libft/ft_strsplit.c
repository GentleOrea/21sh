/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 19:44:39 by tcharrie          #+#    #+#             */
/*   Updated: 2018/02/08 14:01:19 by tcharrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

static size_t		ft_count_words(char const *str, char *c)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (*str && ft_isin(*str, c))
		str++;
	while (*str)
	{
		i++;
		while (*str && !ft_isin(*str, c))
			str++;
		while (*str && ft_isin(*str, c))
			str++;
	}
	return (i + 1);
}

static size_t		ft_strlenn(char const *str, char *c)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] && !ft_isin(str[i], c))
		i++;
	return (i);
}

static char const	*ft_fill_tab(size_t num, char **tab, char const *str,
		char *c)
{
	size_t	i;
	size_t	j;

	while (str && *str && ft_isin(*str, c))
		str++;
	i = ft_strlenn(str, c);
	if (!(tab[num] = (char*)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	j = 0;
	while (j < i)
	{
		tab[num][j] = str[j];
		j++;
	}
	tab[num][j] = '\0';
	while (str[i] && ft_isin(str[i], c))
		i++;
	return (&(str[i]));
}

char				**ft_strsplit(char const *s, char *c)
{
	size_t	i;
	char	**tab;

	i = ft_count_words(s, c);
	if (!(tab = (char **)malloc(sizeof(char *) * i)))
		return (NULL);
	i = 0;
	while (s && *s && ft_isin(*s, c))
		s++;
	while (s && *s)
	{
		s = ft_fill_tab(i, tab, s, c);
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
