/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_newline.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 11:48:59 by tcharrie          #+#    #+#             */
/*   Updated: 2018/05/07 12:30:07 by tcharrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/sh.h"

int		ft_read_newline(t_line *line, int *val, t_parser **pars)
{
	t_parser	*tmp;

	if (!pars)
		return (-1);
	tmp = *pars;
	ft_printchar(line, "\n", val);
	if (val[4] && !ft_separator_active(line->line,
			val[0] - 1, &val[10], &val[11]))
	{
		if (!(tmp = count_parser(&(line->line)[val[5]])))
			return (-1);
		if (tmp->comm)
		{
			val[4] = 0;
			val[0] = val[3];
		}
		if (tmp->comm || tmp->wait)
			val[5] = val[0];
		else
			return (1);
	}
	else if (!val[4])
		return (ft_read_newline_eof(line, val, pars));
	return (0);
}

int		ft_read_newline_eof(t_line *line, int *val, t_parser **pars)
{
	t_parser	*tmp;

	tmp = *pars;
	val[9] = 0;
	if ((ft_strlen(tmp->comm) == 0 && ft_strlen(&(line->eof)[val[5]])) == 1
	|| !ft_strncmp(&(line->eof)[val[5]], tmp->comm, ft_strlen(tmp->comm) - 1))
	{
		val[9] = (tmp->next == 0 && tmp->wait == 0);
		ft_strdel(&(tmp->comm));
		*pars = tmp->next;
		ft_memdel((void*)&tmp);
	}
	val[3] = val[0];
	val[4] = (pars == 0);
	val[5] = (val[4] ? (int)ft_strlen(line->line) : val[0]);
	val[0] = (val[4] ? val[5] : val[0]);
	return (val[9]);
}
