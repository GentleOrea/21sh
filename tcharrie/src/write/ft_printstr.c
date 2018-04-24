/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 12:22:27 by tcharrie          #+#    #+#             */
/*   Updated: 2018/04/23 15:34:09 by tcharrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/sh.h"

int		ft_printstr(t_line *line, char *str, int *val)
{
	int	i;
	char	*tmp;

	if (!str || !line || !val || !(tmp = (val[4] ? line->line : line->eof)))
		return (-1);
	i = (int)ft_strlen(str);
	if ((val[10] = val[0] + i + (int)ft_strlen(&tmp[val[0]])) >=
		(val[4] ? line->size_line : line->size_eof))
		if (ft_realloc_line(line, val, (val[10] + 30)) == -1)
			return (-1);
	tmp = (val[4] ? line->line : line->eof);
	if (ft_insert_noalloc(&tmp[val[0]], str, i) == -1)
		return (-1);
	ft_printf("{whiteblack}%s", str);
	val[0] += i;
	if ((val[6] = tgetnum("co")) <= 0)
		return (-1);
	val[9] = ft_lenline_v(tmp, val[0]);
	if (val[9] && val[9] % val[6] == 0)
		ft_getdown();
	return (ft_printinsert(line, val));
}
