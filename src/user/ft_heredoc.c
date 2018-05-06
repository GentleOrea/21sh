/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heredoc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 12:54:57 by tcharrie          #+#    #+#             */
/*   Updated: 2018/04/24 13:10:44 by tcharrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/sh.h"

int		ft_heredoc_purge(char *str, int size)
{
	int	i;
	int	j;
	int	k;
	int	t;

	i = 0;
	j = 0;
	if (!str)
		return (-1);
	while (i < size)
	{
		while (i < size && !str[i])
			str[j++] = str[i++];
		k = ft_strlento(&str[i], '\n');
		if (i < size && k + 1 < ft_strlen(&str[i]))
		{
			t = 0;
			while (k-- >= 0)
				str[j++] = str[i++];
		}
		else if (i < size)
			i += ft_strlen(&str[i]) + 1;
	}
	return (1);
}
