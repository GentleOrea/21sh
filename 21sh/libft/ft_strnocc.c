/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnocc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/17 16:07:16 by tcharrie          #+#    #+#             */
/*   Updated: 2017/12/27 10:10:50 by tcharrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnocc(char *str, char c, int n)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (*str && n > 0)
	{
		if (*str == c)
			i += 1;
		str++;
		n--;
	}
	return (i);
}