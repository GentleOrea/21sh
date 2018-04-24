/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlenin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 11:48:14 by tcharrie          #+#    #+#             */
/*   Updated: 2018/03/22 16:16:33 by tcharrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strlenin(char *str, char *lim)
{
	int	i;

	if (!str || !lim)
		return (0);
	i = 0;
	while (str[i] && ft_isin(str[i], lim))
		i++;
	return (i);
}
