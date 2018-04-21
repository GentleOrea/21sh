/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_capitalize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 15:07:33 by tcharrie          #+#    #+#             */
/*   Updated: 2017/11/19 16:19:31 by tcharrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_capitalize(char *str)
{
	size_t	i;

	if (!str)
		return (NULL);
	if (ft_islower(*str))
		*str = *str + 'A' - 'a';
	if (!*str)
		return (str);
	i = 1;
	while (str[i])
	{
		if (ft_islower(str[i]) && (!ft_isupper(str[i - 1]) &&
					!ft_islower(str[i - 1])))
			str[i] = str[i] + 'A' - 'a';
		else if (ft_isupper(str[i]) && (ft_islower(str[i - 1]) ||
					ft_isupper(str[i - 1])))
			str[i] = str[i] + 'a' - 'A';
		i++;
	}
	return (str);
}
