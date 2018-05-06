/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specialchar.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 11:47:33 by tcharrie          #+#    #+#             */
/*   Updated: 2018/05/06 14:50:38 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/sh.h"

int		ft_strprefix(char *pref, char *str)
{
	int	i;

	if (!pref || !str)
		return (0);
	i = 0;
	while (pref[i] && pref[i] == str[i])
		i++;
	if (pref[i])
		return (0);
	return (i);
}

int		ft_specialchar(t_line *line, char *str, int *val)
{
	int	i;

	i = 0;
	if (ft_isin(*str, "\t\r\f\v"))
		return (1);
	else if (ft_strprefix("\33\133\61\73\61\60\104", str) && (i = 7))
		ft_selected_moveleft(line, val);
	else if (ft_strprefix("\33\133\61\73\61\60\103", str) && (i = 7))
		ft_selected_moveright(line, val);
	else if (ft_abs(*str) == '\75' && (i = 1))
		ft_selected_cpy(line, val);
	else if (ft_abs(*str) == '\36' && ft_abs(str[1]) == '\170' &&
			ft_abs(str[2]) == '\146' && (i = 3))
		ft_selected_paste(line, val);
	else if (val[2])
		ft_selected_reset(line, val);
	else if (ft_strprefix("\33[1;2A", str) && (i = 6))
		ft_move_up(line, val);
	else if (ft_strprefix("\33[1;2B", str) && (i = 6))
		ft_move_down(line, val);
	else
		return (ft_specialchar_aux(line, str, val));
	return (i);
}

int		ft_specialchar_aux(t_line *line, char *str, int *val)
{
	int	i;

	i = 0;
	if (ft_strprefix("\33[F", str) && (i = 3))
		ft_move_toend(line, val);
	else if ((i = ft_strprefix("\33[A", str)))
		ft_move_tohist(line, val, 1);
	else if (ft_strprefix("\33[B", str) && (i = 3))
		ft_move_tohist(line, val , -1);
	else if (ft_strprefix("\33[D", str) && (i = 3))
		ft_move_left(line, val);
	else if (ft_strprefix("\33[C", str) && (i = 3))
		ft_move_right(line, val);
	else if ((i = ft_strprefix("\33[1;2D", str)))
		ft_move_wordl(line, val);
	else if ((i = ft_strprefix("\33[1;2C", str)))
		ft_move_wordr(line, val);
	else if ((i = ft_strprefix("\33[H", str)))
		ft_move_tohome(line, val);
	else if ((i = ft_strprefix("\33\133\61\73\62\110", str)))
		ft_move_tolinel(line, val);
	else if ((i = ft_strprefix("\33\133\61\73\62\106", str)))
		ft_move_toliner(line, val);
	return (i);
}
