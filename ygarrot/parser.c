/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 16:22:30 by ygarrot           #+#    #+#             */
/*   Updated: 2018/04/23 16:32:13 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

/*
** Split la chaine de caractere en fonction de ';' && '&'
*/

void	medium_split(t_parser *c, char **ammoc)
{
	int		i[2];
	char	*tab[3] = {"&"};
	char	*del;
	char	*str;

	del = NULL;
	ft_bzero(i, sizeof(i));
	while (*ammoc)
	{
		str = *ammoc;
		while ((i[1] = search_op(&str[i[0]], tab)) >= 0)
		{
			c = easy_split(c, del = ft_strndup(&str[i[0]], i[1]), 32);
			i[0] += i[1] + 1;
		}
		ft_memdel((void**)&del);
		c = easy_split(c, &str[i[0]], 0);
		ammoc++;
	}
}

/*
** Split la chaine de caractere en fonction de '||' && '|' && '&&'
** les places dans une listes et set leur value
*/

t_parser	*easy_split(t_parser *c, char *str, char isamp)
{
	int		ind;
	int		i[2];
	int		len;

	i[1] = 0;
	while ((ind = search_op(str, M_SEP)) >= 0)
	{
		i[0] = -1;
		while (M_SEP[++i[0]] &&
				!ft_strnstr(&str[ind], M_SEP[i[0]], len = ft_strlen(M_SEP[i[0]])))
			;
		c = push_front(c, ft_strndup(str, ind), i[1] );
		i[1] = 1 << i[0];
		str = &str[ind + len];
	}
	c = push_front(c, ft_strdup(str), i[1] | isamp);
	return (c);
}

void	hard_split(t_parser *c, char *str)
{
	char	**tab;
	t_parser	par;
	int		i;

	i = -1;
	count_parser(&par, str);
	mallcheck(tab = ft_strsplit_comm(str, ";"));
	medium_split(c, tab);
	ft_free_dblechar_tab(tab);
}
