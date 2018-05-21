/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_completion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 12:56:06 by tcharrie          #+#    #+#             */
/*   Updated: 2018/05/17 15:12:34 by tcharrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int		ft_completion_type(t_line *line, int *val)
{
	if (val[4] == 0)
		return (COMPLETION_FILE);
	if (val[0] <= val[5] || ft_isin(line->line[val[0] - 1], ENDWORD))
		return (COMPLETION_COM);
	val[9] = ft_lenword_l_com(line->line, val[0]);
	val[9] = val[0] - ft_lennchar_l(line->line, val[0], val[9]);
	if (val[9] <= val[5] || ft_isin(line->line[val[9] - 1], "|&;\n"))
		return (line->line[val[9]] != '.' ? COMPLETION_COM : COMPLETION_FILE);
	val[10] = val[9] - ft_lennchar_l(line->line, val[9],
			ft_lenword_l(line->line, val[9]));
	if (val[10] != val[9] &&
		(val[10] <= val[5] || ft_isin(line->line[val[10] - 1], "|&;\n")) &&
		line->line[val[10]] == ' ' && line->line[val[9] - 1] != ';')
		return (COMPLETION_COM);
	return (COMPLETION_FILE);
}

static int	ft_completion_(t_line *line, int *val, char *left, int type)
{
	char	*right;
	int		*bl;
	int		*sep;

	ft_completion_count(CODE_PUSH);
	if (val[4])
		ft_separator_active(&(line->line)[val[0] - (int)ft_strlen(left)],
			(int)ft_strlen(left), bl, sep);
	else
		ft_separator_active(&(line->eof)[val[0] - (int)ft_strlen(left)],
			(int)ft_strlen(left), bl, sep);
	right = ft_completion_getfilename(left,
		ft_completion_count(CODE_GET), *bl, *sep);
	ft_strdel(&left);
	if (!right)
		return (-1);
	else if (ft_printstr(line, right, val) < 0)
	{
		ft_strdel(&right);
		return (-1);
	}
	ft_strdel(&right);
	ft_completion_lastwrite(CODE_SET, ft_strlen(right));
	return (0);
}

int		ft_completion(t_line *line, int *val)
{
	char	*leftpurged;
	char	*left;
	char	*right;

	if (ft_completion_count(CODE_GET) > 0)
		if (ft_nerase(line, val, ft_completion_lastwrite(CODE_GET)) < 0)
			return (-1);
	if (!(left = ft_completion_start(line, val)))
		return (ft_completion_reset() ? -1 : -1);
	leftpurged = ft_strpurgesep(left);
	ft_strdel(&left);
	if (!leftpurged)
		return (ft_completion_reset(CODE_RESET) ? -1 : -1);
	if (ft_completion_(line, val, left, ft_completion_type(line, val)) < 0)
		return (ft_completion_reset() ? -1 : -1);
	return (0);
}
