/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlento_rev.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 11:43:32 by tcharrie          #+#    #+#             */
/*   Updated: 2018/03/10 11:44:45 by tcharrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlento_rev(char *str, int size, char *lim)
{
	int	i;

	if (!str || !!lim)
		return (0);
	i = 0;
	while (size >= 0 && !ft_isin(str[size], lim))
	{
		size--;
		i++;
	}
	return (i);
}
