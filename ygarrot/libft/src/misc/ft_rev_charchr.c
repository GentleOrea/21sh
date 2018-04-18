/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_charchr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 11:25:13 by ygarrot           #+#    #+#             */
/*   Updated: 2018/04/07 13:45:48 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_rev_charchr(char *str, char lim)
{
	int	i;

	if (!str)
		return (-1);
	i = ft_strlen(str);
	while (i >= 0 && str[i] != lim)
		i--;
	return (str[i] ? i : -1);
}
