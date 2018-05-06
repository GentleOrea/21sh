/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 13:33:27 by tcharrie          #+#    #+#             */
/*   Updated: 2018/05/06 16:04:26 by tcharrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/sh.h"

int		ft_read(t_line *line, int *val)
{
	char		buf[BUFFSIZE + 1];
	char		tmp[2 * BUFFSIZE + 1];
	t_parser	*pars;
	int			i[3];

	pars = 0;
	ft_bzero((void*)tmp, 2 * BUFFSIZE);
	while (1)
	{
		ft_bzero((void*)i, sizeof(i));
		if (ft_sigint(0))
			return (ft_sigint_clear(line) ? -1 : -1);
		val[9] = read(0, buf, 9);
		if (ft_sigint(0))
			return (ft_sigint_clear(line) ? -1 : -1);
		buf[val[9]] = 0;
		ft_strcat(tmp, buf);
		if (ft_read_process(line, val, tmp, &pars))
			return (1);
	}
	return (0);
}

int		ft_read_process(t_line *line, int *val, char *tmp, t_parser **pars)
{
	int	i[3];

	while (!i[0] || ft_strlen(tmp) - i[1] > BUFFSIZE)
	{
		if (*tmp == 3 && (val[4] ? line->line : line->eof)[val[0]])
			ft_delete(line, val);
		else if (*tmp == 3)
			ft_exit(0, 0);
		else if (*tmp == '\n')
			return (1);
		else if (*tmp == '\n' && ft_read_newline(line, val, pars) == 1)
			return (1);
		else if (!(i[2] = ft_specialchar(line, &tmp[i[1]], val)))
		{
			i[2] = ft_lentospecial(&tmp[i[0]]);
			ft_printnchar(line, &tmp[i[1]], val, i[2]);
		}
		i[0] = 1;
		i[1] += i[2];
	}
	return (0);
}
