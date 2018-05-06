/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getline.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 10:52:28 by tcharrie          #+#    #+#             */
/*   Updated: 2018/05/06 13:30:52 by tcharrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

/*
** Cette fonction prend une chaine de charactere, une position,
** et determine si on est dans un separateur, renvoyant selon le format
** de ft_separator
** Utile pour determiner si un '\n' est actif lors de la recuperation
** de ligne
*/

int		ft_separator_active(char *str, int pos, int *bl, int *sep)
{
	int	i;

	i = 0;
	*bl = 0;
	*sep = 0;
	while (str[i] && i < pos)
	{
		*sep = ft_separator(str[i], *sep, *bl);
		*bl = (!*bl && *sep != '\'' && str[i] == '\n');
		i += ft_lenchar_r(str, i);
	}
	return (*sep || *bl);
}

/*
**	Renvoie la nouvelle valeur du séparateur
** sep > 0 : Signifie qu'on est dans dans une chaine, regarde si on est à
** la fin et renvoie 0 si oui, sep sinon
** sep == 0 : Regarde si on a un nouveau séparateur
**	Un ' ou un ", renvoie sa valeur
**	Autre : 0
*/

int		ft_separator(char c, int sep, int bl)
{
	if ((sep == '\'' || (sep && !bl)) && c == sep)
		return (0);
	if (!sep && !bl && (c == '\'' || c == '"'))
		return ((int)c);
	return (sep);
}
