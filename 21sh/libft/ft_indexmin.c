/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_indexmin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 15:22:06 by tcharrie          #+#    #+#             */
/*   Updated: 2017/11/19 15:28:00 by tcharrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_indexmin(int *tab, size_t len)
{
	size_t	i;
	int		j;

	if (!tab || len == 0)
		return (-1);
	i = 0;
	j = 0;
	while (i < len)
	{
		if (tab[i] < tab[j])
			j = (int)i;
		i++;
	}
	return (j);
}
