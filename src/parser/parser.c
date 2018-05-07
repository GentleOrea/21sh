/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 17:14:50 by ygarrot           #+#    #+#             */
/*   Updated: 2018/05/07 13:14:20 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

/*
** Split la chaine de caractere en fonction de ';' && '&'
*/

void		medium_split(t_parser *c, char **ammoc)
{
	int		i[2];
	char	**tb;
	char	*del;
	char	*str;

	del = NULL;
	tb = (char *[2]){"&"};
	ft_bzero(i, sizeof(i));
	while (*ammoc)
	{
		str = *ammoc;
		while ((i[1] = search_op(&str[i[0]], tb)) >= 0)
		{
			del = ft_strndup(&str[i[0]], i[1]);
			c = easy_split(c, del, 32);
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
		c = push_front(c, ft_strndup(str, ind), i[1]);
		i[1] = 1 << i[0];
		str = &str[ind + len];
	}
	c = push_front(c, ft_strdup(str), i[1] | isamp);
	return (c);
}

int			hard_split(t_shell *sh, char *str)
{
	char		**tb;
	t_parser	*par;

	if (!str)
		return (1);
	if (!(par = count_parser(str)))
		return (-1);
	free_parser(par);
	mallcheck(par = (t_parser*)ft_memalloc(sizeof(t_parser)));
	mallcheck(tb = ft_strsplit_comm(str, "\n;"));
	medium_split(par, tb);
	ft_free_dblechar_tab(tb);
	split_co(sh, par);
	return (1);
}
