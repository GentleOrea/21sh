/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 12:48:50 by tcharrie          #+#    #+#             */
/*   Updated: 2018/05/07 13:50:38 by tcharrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

char	*ft_init_aff(int *val)
{
	char	*local;
	size_t	i;
	int		c;

	c = 2;
	if (!(local = getcwd(0, 1)))
		write(1, "$>", 2);
	else
	{
		i = ft_strlen(local);
		while (i && local[i] != '/')
			i--;
		if (local[i] == '/')
			i++;
		c = write(1, &(local[i]), ft_strlen(&(local[i])));
		c += write(1, " >", 2);
	}
	val[0] = c;
	val[1] = c;
	val[5] = c;
	if (!(local = (char*)ft_memalloc(c + 1)))
		return (0);
	ft_memset((void*)local, 100, c);
	return (local);
}

int		writechar(int c)
{
	return (write(STDOUT_FILENO, &c, 1));
}
