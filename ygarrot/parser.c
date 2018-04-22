/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 16:22:30 by ygarrot           #+#    #+#             */
/*   Updated: 2018/04/21 15:01:08 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

/*
** Split la chaine de caractere en fonction de ';' && '&'
*/

void	medium_split(t_parser *c, char **ammoc)
{
	int		ind;
	char	*tab[3] = {"&"};
	t_parser	*tmp;
	char	*del;
	char	*str;

	tmp = c;
	del = NULL;
	while (*ammoc)
	{
		str = *ammoc;
		while ((ind = search_op(str, tab)) >= 0)
		{
			c = easy_split(c, del = ft_strndup(str, ind), 32);
			str = &str[ind + 1];
		}
		ft_memdel((void**)&del);
		c = easy_split(c, str, 0);
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
