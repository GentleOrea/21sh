/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specialchar.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 11:47:33 by tcharrie          #+#    #+#             */
/*   Updated: 2018/05/06 11:48:48 by tcharrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/sh.h"

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
