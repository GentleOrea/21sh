/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_separator.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 11:09:28 by tcharrie          #+#    #+#             */
/*   Updated: 2018/05/21 11:17:39 by tcharrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

/*
** Cette fonction prend une chaine de charactere, une position,
** et determine si on est dans un separateur, renvoyant la valeur de bq
** Utile pour determiner si un '\n' est actif lors de la recuperation
** de ligne
** Elle ne verifie pas les erreurs de parsing tel que `ls '`
*/

int		ft_separator_active(char *str, int pos, int *sep, int *bl)
{
	int	i;
	int	bq;

	i = 0;
	if (bl)
		*bl = 0;
	if (sep)
		*sep = 0;
	bq = 0;
	while (str[i] && i < pos)
	{
		ft_separator(str[i], sep, bl, &bq);
		i += ft_lenchar_r(str, i);
	}
	return (bq);
}

/*
**	Renvoie la nouvelle valeur du séparateur
** sep > 0 : Signifie qu'on est dans dans une chaine, regarde si on est à
** la fin et renvoie 0 si oui, sep sinon
** sep == 0 : Regarde si on a un nouveau séparateur
**	Un ' ou un ", renvoie sa valeur
**	Autre : 0
*/

void	ft_separator(char c, int *sep, int *bl, int *bq)
{
	if (sep && *sep && *sep == c && (!bl || !*bl) && (!bq || !*bq))
		*sep = 0;
	else if (sep && !*sep && ft_isin(c, "'\"") && (!bl || !*bl))
		*sep = c;
	if (bq && *bq == '`' && c == '`' && (!bl || !*bl))
		*bq = 0;
	else if (bq && !*bq && c == '`' && (!sep || *sep != '\'') && (!bl || !*bl))
		*bq = '`';
	if (bl && c == '\\' && !*bl && (!sep || *sep != '\''))
		*bl = 1;
	else if (bl && *bl)
		*bl = 0;
}
