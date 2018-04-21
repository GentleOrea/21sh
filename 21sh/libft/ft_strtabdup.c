/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtabdup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/04 18:08:12 by tcharrie          #+#    #+#             */
/*   Updated: 2018/02/09 10:59:29 by tcharrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strtabdup(char **tab)
{
	char	**dup;
	int		i;

	if (!tab)
		return (NULL);
	i = 0;
	while (tab[i])
		i++;
	if (!(dup = (char**)malloc(sizeof(char*) * (i + 1))))
		return (NULL);
	i = 0;
	while (tab[i])
	{
		if (!(dup[i] = ft_strdup(tab[i])))
		{
			while (i > 0 && --i >= 0)
				free(dup[i]);
			free(dup);
			return (NULL);
		}
		i++;
	}
	dup[i] = NULL;
	return (dup);
}
