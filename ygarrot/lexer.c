/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 15:40:03 by ygarrot           #+#    #+#             */
/*   Updated: 2018/04/19 14:07:04 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

/*
** les deux fonctions en dessous permettent de compter le nombre de here_doc
** split les commandes en fonction de tout les type de separateur.
** Pas super clean mais évite d'allouer de la mem
** Gere les erreurs de parsing, ne gere (surement) pas toutes les erreurs
*/

int		get_hdoc(char *str, int i, t_comm *par)
{
	int	hdoc;

	if ((hdoc = is_sep(&str[i], par, REDI)))
	{
		if ((ft_strnstr(&str[i], "<<", 2) && (i += hdoc)) || (i += hdoc))
		{
			while (str[i] == ' ')
				i++;
			par = push_front(par, ft_strndup(&str[i], (hdoc = search_op(&str[i],
			HD) >= 0 ? hdoc + 1 : ft_strlen(&str[i]))));
		}
		while (str[i] == ' ')
			i++;
		if (!(hdoc = 0) && is_sep(&str[i], par, ALL))
			return (-1);
	}
	else
		i++;
	return (i);
}

int		sizeof_comm(char *str, t_comm *par)
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
	if (str[i] && (str[i] == ';' || ft_strnstr(&str[i], ";;", 2)))
		return (!ft_strnstr(&str[i], ";;", 2) ? i | 1 : -1);
	return (i || !str[i] ? i + sep : -1);
}

void	count_comm(t_comm *par, char *str)
{
	int		i;
	int		sep;

	i = 0;
	while (str[i])
	{
		while (str[i] && str[i] == ' ')
			i++;
		sep = sizeof_comm(&str[i], par);
		if (sep < 0)
		{
			ft_printf("yosh: parse error near `%s'\n", par->op);
			exit(EXIT_FAILURE) ;
		}
		i += sep;
	}
}
