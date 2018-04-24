/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insert.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 14:36:52 by tcharrie          #+#    #+#             */
/*   Updated: 2018/03/08 14:45:58 by tcharrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_insert(char **str, char *in, size_t to, size_t size)
{
	char	*tmp;
	size_t	i;
	size_t	j;

	if (!str || !*str)
		return (-1);
	i = 0;
	j = 0;
	if (!(tmp = (char*)malloc(sizeof(char) * (ft_strlen(*str) + size + 1))))
		return (-1);
	while (i < to)
	{
		tmp[i] = str[0][i];
		i++;
	}
	while (j < size)
		tmp[i++] = in[j++];
	while (str[0][to])
		tmp[i++] = str[0][to++];
	tmp[i] = 0;
	free(*str);
	*str = tmp;
	return (1);
}
