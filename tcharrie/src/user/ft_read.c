/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 13:33:27 by tcharrie          #+#    #+#             */
/*   Updated: 2018/04/23 11:51:34 by tcharrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/sh.h"
#include <term.h>

int		ft_specialchar(t_line *line, char *str, int *val)
{
	if (ft_isin(*str, "\t\r\f\v"))
		return (1);
	else if (!ft_strcmp(str, tgetstr("ku", 0)))
		return (1);
//		ft_move_tohist(line, val, 1);
	else if (!ft_strcmp(str, tgetstr("kd", 0)))
		return (1);
//		ft_move_tohist(line, val , -1);
	else if (!ft_strcmp(str, tgetstr("kl", 0)))
		ft_move_left(line, val);
	else if (!ft_strcmp(str, tgetstr("kr", 0)))
		ft_move_right(line, val);
	else if (!ft_strcmp(str, tgetstr("#4", 0)))
		ft_move_wordl(line, val);
	else if (!ft_strcmp(str, tgetstr("%i", 0)))
		ft_move_wordr(line, val);
	else if (!ft_strcmp(str, tgetstr("kF", 0))) //shift + up
		ft_move_up(line, val);
	else if (!ft_strcmp(str, tgetstr("kR", 0))) //shift + down
		ft_move_down(line, val);
	else if (!ft_strcmp(str, tgetstr("kh", 0)))
		ft_move_tohome(line, val);
	else
		return (ft_specialchar_aux(line, str, val));
	return (1);
}

int		ft_specialchar_aux(t_line *line, char *str, int *val)
{
	if (!ft_strcmp(str, tgetstr("@7", 0)) || !ft_strcmp(str, tgetstr("*7", 0)))
		ft_move_toend(line, val);
	else
		return (0);
	return (1);
}

int		ft_read(t_line *line, int *val)
{
	char	buf[10];
	char	tmp[20];

	while (1)
	{
		if (ft_sigint(0))
			return (ft_sigint_clear(line));
		val[9] = read(0, buf, 9);
		if (ft_sigint(0))
			return (ft_sigint_clear(line));
		buf[val[9]] = 0;
		if (*buf == 3 && (val[4] ? line->line : line->eof)[val[0]])
			ft_delete(line, val);
		else if (*buf == 3)
			ft_exit(0, 0);
//		else if (*buf == '\n' && !val[4] && !ft_separator_active(line->line ,
//				val[0], &val[10], &val[11]))
//			;
		else if (!ft_specialchar(line, buf, val))
			ft_printchar(line, buf, val);
	}
	return (1);
}
