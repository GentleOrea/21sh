/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 14:35:51 by tcharrie          #+#    #+#             */
/*   Updated: 2018/01/20 14:43:42 by tcharrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strrev(char *str)
{
	size_t	i;
	size_t	j;
	char	c;

	if (!str)
		return ;
	if ((i = ft_strlen(str)))
		i--;
	j = 0;
	while (j < i)
	{
		c = str[i];
		str[i] = str[j];
		str[j] = c;
		i--;
		j++;
	}
}
