/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 16:22:30 by ygarrot           #+#    #+#             */
/*   Updated: 2018/04/17 11:54:44 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

/*
** Useless, odd try
*/

int		size_hard_split(char *str)
{
	int		i;
	char	q;

	i = 0;
	
	while (str[i] && !ft_isin(str[i], H_SEP))
	{
		if (ft_isin(str[++i], QUOTES) && (q = str[i] == '"' ? '"' : '\''))
			while (str[i] && str[++i] != q)
				;
	}
	if (str[i] == ';' || ft_strnstr(&str[i], ";;", 2))
		return (!ft_strnstr(&str[i], ";;", 2) ? 0 : -1);
	return (i || !str[i] ? i : -1);
}

/*
** Split la chaine avec comme splitchar ';' && '&'
*/

void	hard_split(t_comm *c, char *str)
{
	char	**tab;
	t_parser par;

	if (count_comm(&par, str) < 0)
		exit(ft_printf("yoo fool\n"));
	mallcheck(tab = ft_strsplit_comm(str, H_SEP));
	while (*tab)
	{
		mallcheck(c->next = (t_comm*)ft_memalloc(sizeof(t_comm)));
		c->comm = *tab;
		c = c->next;
		tab++;
	}
}

void	medium_split(t_comm *c, char *str)
{
	char	**tab;
	t_parser par;

	if (count_comm(&par, str) < 0)
		exit(ft_printf("yoo fool\n"));
	mallcheck(tab = ft_strsplit_comm(str, H_SEP));
	while (*tab)
	{
		mallcheck(c->next = (t_comm*)ft_memalloc(sizeof(t_comm)));
		c->comm = *tab;
		c = c->next;
		tab++;
	}
}
