/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insert.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/21 14:52:25 by tcharrie          #+#    #+#             */
/*   Updated: 2018/04/21 14:52:26 by tcharrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/sh.h"

/*
** Ajouter len éléments de str au début de src qui est de taille len
** Considère que src est suffisament grand pour l'accueillir
*/

int		ft_insert_noalloc(char *src, char *str, int size)
{
	int	len;

	if (!src || !str)
		return (-1);
	if (size < 1)
		return (1);
	len = ft_strlen(src) + size;
	dprintf(2, "/%d -> %d\\", len, size);
	while (len-- > size)
		src[len] = src[len - size];
	dprintf(2, "/%s\\", str);
	while (size-- > 0)
		src[size] = str[size];
	return (1);
}
