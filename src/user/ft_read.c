/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 13:33:27 by tcharrie          #+#    #+#             */
/*   Updated: 2018/05/06 11:58:58 by tcharrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/sh.h"
#include <term.h>

int		ft_read(t_line *line, int *val)
{
	char		buf[BUFFSIZE + 1];
	char		tmp[2 * BUFFSIZE + 1];
	t_parser	*pars;
	int			i[2];

	pars = 0;
	ft_bzero((void*)tmp, 2 * BUFFSIZE);
	while (1)
	{
		ft_bzero((void*)i, sizeof(i));
		if (ft_sigint(0))
			return (ft_sigint_clear(line));
		val[9] = read(0, buf, 9);
		if (ft_sigint(0))
			return (ft_sigint_clear(line));
		buf[val[9]] = 0;
		ft_strcat(tmp, buf);
		while (!i[0] || ft_strlen(tmp) >= 8)
		{
			if (*tmp == 3 && (val[4] ? line->line : line->eof)[val[0]])
				ft_delete(line, val);
			else if (*tmp == 3)
				ft_exit(0, 0);
			else if (*tmp == '\n' && ft_read_newline(line, val, &pars) == 1)
				return (1);
			else if (!ft_specialchar(line, tmp, val))
				ft_printchar(line, buf, val);
			i[0] = 1;
		}
	}
}
