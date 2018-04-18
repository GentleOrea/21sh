/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 16:22:30 by ygarrot           #+#    #+#             */
/*   Updated: 2018/04/18 17:29:51 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

/*
** recherche la premiere occurence d'une chaine du tableau donné en param
** dans la chaine donné en second param
*/

int		search_op(char *str, char **op)
{
	int	i;
	int	ind;

	i = -1;
	while (str[++i])
	{
		i += skip_comm(&str[i]);
		ind = -1;
		while (op[++ind])
			if (ft_strnstr(&str[i], op[ind] , ft_strlen(op[ind])))
				if (op[0][0] != '&' || !str[i]
						|| (str[i + 1] != '&' && (i <= 0 || str[i - 1] != '&')))
					return (i);
	}
	return (0);
}

/*
** Split la chaine de caractere en fonction de ';' && '&'
*/

void	medium_split(t_comm *c, char **ammoc)
{
	int		ind;
	char	*tab[3] = {"&"};
	t_comm	*tmp;
	char	*del;
	char	*str;

	tmp = c;
	del = NULL;
	while (*ammoc)
	{
		str = *ammoc;
		while ((ind = search_op(str, tab)))
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


t_comm	*easy_split(t_comm *c, char *str, char isamp)
{
	int		ind;
	int		i[2];
	int		len;

	while ((ind = search_op(str, M_SEP)))
	{
		i[0] = -1;
		while (M_SEP[++i[0]] &&
				!ft_strnstr(&str[ind], M_SEP[i[0]], len = ft_strlen(M_SEP[i[0]])))
			;
		c = push_front(c, ft_strndup(str, ind));
		c->type = i[1];
		c = c->next;
		i[1] = i[0];
		str = &str[ind + len];
	}
	c = push_front(c, ft_strdup(str));
	c->type = i[1] | isamp;
	return (c);
}

void	hard_split(t_comm *c, char *str)
{
	char	**tab;
	t_comm	par;
	int		i;

	i = -1;
	count_comm(&par, str);
	mallcheck(tab = ft_strsplit_comm(str, ";"));
	medium_split(c, tab);
	ft_free_dblechar_tab(tab);
}

int main(int ac, char **av)
{
	t_comm *co = (t_comm*)ft_memalloc(sizeof(t_comm));

	(void)av;(void)ac;
	hard_split(co, av[1]);
	while (co)
	{
		ft_printf("%s\n", co->comm);
		co = co->next;
	}
}
