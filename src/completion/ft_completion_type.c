/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_completion_type.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 11:21:22 by tcharrie          #+#    #+#             */
/*   Updated: 2018/05/21 11:21:23 by tcharrie         ###   ########.fr       */
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
