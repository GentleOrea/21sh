/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_len.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 13:23:46 by tcharrie          #+#    #+#             */
/*   Updated: 2018/03/10 14:56:31 by tcharrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/sh.h"

/*
** Renvoie le nb de caractere dont se deplacer a gauche lors d'un shift + left
** Si on est dans un mot ET pas a son debut envoie au debut du mot
** Si on n'est pas dans un mot ou au debut d'un mot ramene au debut du mot\
**	precedent
** Peut ramener au debut de la ligne, meme si celle-ci commence par des espaces
*/

int		ft_lento_prevword(t_line *line, int *val)
{
	int		i;
	int		pos;
	int		sep;

	if (val[4] == 0)
		return (0);
	i = val[5];
	pos = i;
	while (i < val[0] && ft_isin(line->line[i], " \n"))
		i++;
	sep = 0;
	while (i < val[0])
	{
		sep = ft_separator(sep, line->line, i);
		if (!sep && ft_isin(line->line[i], " \n"))
			pos = i;
	}
	return (pos);
}

int	ft_lento_nextword(t_line *line, int *vall)
{
	return (1);
}
