/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getpos.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/21 13:34:36 by tcharrie          #+#    #+#             */
/*   Updated: 2018/05/06 13:26:18 by tcharrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/sh.h"

static int	ft_getpos_a(int *x, int *y, char *buff, int re)
{
	*x = 0;
	*y = 0;
	buff[re++] = 0;
	while (buff[re] && (buff[re] < 48 || buff[re] > 57))
		re++;
	while (buff[re] >= 48 && buff[re] <= 57)
		*x = (*x) * 10 + (buff[re++]) - '0';
	if (buff[re++] != ';')
	{
		ft_addtofd(buff, STDIN_FILENO);
		ft_addtofd(&buff[re - 1], STDIN_FILENO);
		return (-1);
	}
	while (buff[re] >= 48 && buff[re] <= 57)
		*y = (*y) * 10 + (int)(buff[re++]) - '0';
	ft_addtofd(&buff[re + 1], STDIN_FILENO);
	ft_addtofd(buff, STDIN_FILENO);
	return (0);
}

int			ft_getpos(int *x, int *y)
{
	char	buff[100];
	int		re;
	int		lim;

	if (!x || !y || !write(STDOUT_FILENO, "\33[6n", 4) || (re = 0))
		return (-1);
	lim = 10;
	ft_bzero((void*)buff, 100);
	while (lim-- > 0 && re < 5 &&
			ft_strlento(buff, '\33') + 5 > (int)ft_strlen(buff))
		re += read(STDIN_FILENO, &buff[re], 99 - re);
	if ((re = ft_strlento(buff, '\33')) + 5 > (int)ft_strlen(buff))
	{
		ft_addtofd(buff, STDIN_FILENO);
		return (-1);
	}
	return (ft_getpos_a(x, y, buff, re));
}
