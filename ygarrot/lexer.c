/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 15:40:03 by ygarrot           #+#    #+#             */
/*   Updated: 2018/04/25 11:24:06 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

/*
** les deux fonctions en dessous permettent de compter le nombre de here_doc
** split les commandes en fonction de tout les type de separateur.
** Pas super clean mais évite d'allouer de la mem
** Gere les erreurs de parsing, ne gere (surement) pas toutes les erreurs
*/

int		get_hdoc(char *str, int i, t_parser *par)
{
	int	hdoc;
	int		red;

	if ((hdoc = is_sep(&str[i], par, REDI)))
	{
		red = get_sep(&str[i], REDI);
		if ((i += hdoc) && red == 4)
		{
			while (str[i] == ' ')
				i++;
			par = push_front(par, ft_strndup(&str[i], (hdoc = search_op(&str[i],
			HD) >= 0 ? hdoc + 1 : ft_strlen(&str[i]))), 0);
		}
		while (str[i] == ' ')
			i++;
		if (((red == 2 || red == 3) && str[i] != '-' && !ft_isdigit(str[i]))
			|| (!(hdoc = 0) && is_sep(&str[i], par, ALL)))
			return (-1);
	}
	else
		i++;
	return (i);
}

int		sizeof_comm(char *str, t_parser *par)
{
	int		i;
	char	sep;

	i = 0;
	sep = 0;
	while (str[i] && !(sep = is_sep(&str[i], par, SEP)))
	{
		i += skip_comm(&str[i]);
		i = get_hdoc(str, i, par);
		if (i < 0)
			return (-1);
	}
	par->wait = (get_sep(&str[i], SEP) < 3 ? 1 : 0);
	if (str[i] && (str[i] == ';' || ft_strnstr(&str[i], ";;", 2)))
		return (!ft_strnstr(&str[i], ";;", 2) ? i | 1 : -1);
	return (i || !str[i] ? i + sep : -1);
}

t_parser	*count_parser(char *str)
{
	int		i;
	t_parser *par;
	int		sep;

	i = 0;
	mallcheck(par = (t_parser*)ft_memalloc(sizeof(t_parser)));
	while (str[i])
	{
		while (str[i] && str[i] == ' ')
			i++;
		sep = sizeof_comm(&str[i], par);
		if (sep < 0)
		{
			ft_printf("yosh: parse error near `%s'\n", par->op);
			return (NULL);
		}
		i += sep;
	}
	return (par);
}
