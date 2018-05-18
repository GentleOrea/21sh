/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_completionstr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 15:18:16 by tcharrie          #+#    #+#             */
/*   Updated: 2018/05/17 15:55:23 by tcharrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

char	*ft_straddsep(char *str, int bl, int sep)
{
	char	*split;
	int		i;
	int		j;

	if (!str)
		return (0);
	if (!(split = (char*)ft_memalloc(2 * ft_strlen(str) + 3)))
		return (0);
	i = 0;
	j = 0;
	while (str[i])
	{
		if (sep && (sep == '\'' || !bl) && str[i] == sep)
			split[j++] = '\\';
		else if (!sep && !bl && ft_isin(str[i], SPECIALCHAR))
			split[j++] = '\\';
		
	}
	return (split);
}