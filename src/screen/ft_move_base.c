/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_bas.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 13:32:18 by tcharrie          #+#    #+#             */
/*   Updated: 2018/05/06 14:04:23 by tcharrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/sh.h"

/*
** Move left of one
** Manages scrolling & co
*/

int		ft_move_left(t_line *line, int *val)
{
	int	ret;

	ret = 1;
	if ((val[6] = tgetnum("co")) <= 0 || !tgetstr("up", 0) || !tgetstr("nd", 0)
			|| !tgetstr("le", 0) || val[0] <= val[5])
		return (-1);
	if (ft_getpos(&val[9], &val[10]))
		return (-1);
	if (val[9] == 1 && val[10] == 1)
		ret = ft_scroll_down(line, val);
	else if (val[10] == 1)
	{
		if (tputs(tgetstr("up", 0), STDOUT_FILENO, writechar) == ERR)
			return (-1);
		val[9] = ft_lenline_v((val[4] ? line->line : line->eof),
					val[0] - 1) % val[6];
		while (val[9]--)
			if (tputs(tgetstr("nd", 0), STDOUT_FILENO, writechar) == ERR)
				ret = -1;
	}
	else if (tputs(tgetstr("le", 0), STDOUT_FILENO, writechar) == ERR)
		ret = -1;
	val[0] -= ft_lenchar_l(val[4] ? line->line : line->eof, val[0]);
	return (ret);
}

int		ft_move_right(t_line *line, int *val)
{
	int	ret;

	ret = 1;
	if ((val[6] = tgetnum("co")) <= 0 || !tgetstr("do", 0) || !tgetstr("le", 0))
		return (-1);
	if ((val[4] ? line->line : line->eof)[val[0]] == 0 || (val[7] =
				tgetnum("li")) <= 0 || ft_getpos(&(val[9]), &(val[10])))
		return (-1);
	if (val[9] == val[7] && (val[10] == val[6] || (val[4] ?
		line->line[val[0]] : line->eof[val[0]]) == '\n'))
		ret = ft_scroll_up(line, val);
	else if (val[10] == val[6] || (val[4] ? line->line[val[0]] :
				line->eof[val[0]]) == '\n')
	{
		if (tputs(tgetstr("do", 0), STDOUT_FILENO, writechar) == ERR)
			ret = -1;
	}
	else if (tputs(tgetstr("nd", 0), STDOUT_FILENO, writechar) == ERR)
		ret = -1;
	val[0] += ft_lenchar_r(val[4] ? line->line : line->eof, val[0]);
	return (ret);
}

/*
** Dans un premier temps déterminer la coordonnée horizontale de la destination
** & le nombre de lignes à remonter.
** Puis y aller étape par étape en commençant par aller à gauche si besoin
** de scroll
*/

void	ft_move_up(t_line *line, int *val)
{
	char	*str;
	int		x;
	int		y;

	if (!(str = (val[4] ? line->line : line->eof)) || ft_getpos(&x, &y))
		return ;
	if ((val[6] = tgetnum("co")) <= 0 || !tgetstr("up", 0) ||
		!tgetstr("le", 0) || !tgetstr("kr", 0))
		exit(3);
	if ((val[7] = tgetnum("li")) <= 0)
		exit(4);
	val[10] = ft_lenline_v(str, val[0]);
	val[11] = val[10] / val[6];
	if ((val[9] = val[0] - ft_lenline_c(str, val[0])) < val[5])
		val[9] = val[5];
	if (val[9] == val[5])
		val[10] += ft_lenline_v(str, val[5]);
	if (val[9] == val[5])
		val[11] -= ft_lenline_v(str, val[5]) / val[6];
	if (val[4] == 0)
		val[12] = 1;
	else if (val[5] == val[9])
		val[12] = (ft_lenline_v(str, val[5]) % val[6]) + 1;
	ft_move_up_bis(str, val, x, y);
}

int		ft_move_down(t_line *line, int *val)
{
	char	*str;
	int		x;
	int		y;

	if ((val[6] = tgetnum("co")) <= 0 || !tgetstr("do", 0) ||
		!tgetstr("le", 0) || ft_getpos(&x, &y))
		return (-1);
	if ((val[7] = tgetnum("li")) <= 0)
		return (-1);
	str = (val[4]) ? (line->line) : (line->eof);
	val[9] = val[0] + ft_strlento(&str[val[0]], '\n');
	val[11] = (ft_lenline_v(str, val[9]) / val[6]) - (ft_lenline_v(str,
		val[0]) / val[6]);
	val[10] = ft_lenline_v(str, val[0]) - ((val[0] -
		ft_lenline_c(str, val[0])) < val[5] ? ft_lenline_v(str, val[5]) : 0);
	if (str[val[9]] == '\n' && val[9]++)
	{
		val[9] += ft_lennchar_r(str, val[9], ft_min(ft_strlento(&str[val[9]],
			'\n'), val[10]));
		val[11] += 1 + (ft_lenline_v(str, val[9]) / val[6]);
	}
	val[12] = (ft_lenline_v(str, val[9]) % val[6]) + 1;
	return (ft_move_down_bis(str, val, x, y));
}
/*
int		main(int ac, char **av, char **env)
{
	int	val[15];
	char	str[100];
	t_line	line[1];
	char	term_buffer[2048];
	char	*s;

	s = (char*)malloc(111);
	ft_initsig();
	ft_init_terminal_data(env);
	ft_setattr();
	line->line = (char*)ft_memalloc(5);
	line->size_line = 5;
	line->eof = "";
	ft_bzero((void*)val, sizeof(val));
	val[4] = 1;
	write(1, "Bl:", 3);
	val[5] = 3;
	val[0] = 3;
	ft_strcat(line->line, "Bl:");
	while (1)
	{
		tgetent(term_buffer, getenv("TERM"));
		val[9] = read(0, str, 90);
		str[val[9]] = 0;
		if (val[9] == 1 && ft_isin(*str, "\t\r\f\v"))
			exit (1);
		else if (!ft_strcmp(str, "\33\133\61\73\61\60\104"))
			ft_selected_moveleft(line, val);
		else if (!ft_strcmp(str, "\33\133\61\73\61\60\103"))
			ft_selected_moveright(line, val);
		else if (ft_abs(str[0]) == '\75')
			ft_selected_cpy(line, val);
		else if (ft_abs(str[0]) == '\36' && ft_abs(str[1]) == '\170' && ft_abs(str[2]) == '\146')
			ft_selected_paste(line, val);
		else if (val[2])
			ft_selected_reset(line, val);
		else if (!ft_strcmp(str, "\33\133\104"))
			ft_move_left(line, val);
		else if (!ft_strcmp(str, "\33\133\103"))
			ft_move_right(line, val);
		else if (!ft_strcmp(str, "\33\133\102"))
			ft_move_tohist(line, val, -1);
		else if (!ft_strcmp(str, "\33\133\101"))
			ft_move_tohist(line, val, 1);
		else if (!ft_strcmp(str, "\33\133\61\73\62\101"))
			ft_move_up(line, val);
		else if (!ft_strcmp(str, "\33\133\61\73\62\102"))
			ft_move_down(line, val);
		else if (!ft_strcmp(str, "\33\133\61\73\62\104"))
			ft_move_wordl(line, val);
		else if (!ft_strcmp(str, "\33\133\61\73\62\103"))
			ft_move_wordr(line, val);
		else if (!ft_strcmp(str, "\33\133\110"))
			ft_move_tohome(line, val);
		else if (!ft_strcmp(str, "\33\133\106"))
			ft_move_toend(line, val);
		else if (!ft_strcmp(str, "\33\133\61\73\62\110"))
			ft_move_tolinel(line, val);
		else if (!ft_strcmp(str, "\33\133\61\73\62\106"))
			ft_move_toliner(line, val);
		else if (val[9] > 1)
		{
			dprintf(2, "This one sucks |%d|%s|\n", val[9], &str[1]);
			val[9] = 0;
			while (str[val[9]])
				dprintf(2, "%o.", ft_abs(str[val[9]++]));
			dprintf(2, "\n");
		}
		else if (*str == 127)
			ft_erase(line, val);
		else if (*str == 'S')
			tputs(tgetstr("sc", 0), 0, writechar);
		else if (*str == 'R')
			tputs(tgetstr("rc", 0), 0, writechar);
		else if (*str == 'E')
			exit(0);
		else if (*str == 'Q')
		{
			val[9] = 0;
			while (val[9] < 9)
				dprintf(2, "|%d|", val[val[9]++]);
			dprintf(2, "\n");
		}
		else
		{
			dprintf(2, ".");
			if (ft_printchar(line, str, val) == -1)
				exit(10);
			dprintf(2, "\n");
		}
	}
	(void)ac;
	(void)av;
	return (0);
}
*/
