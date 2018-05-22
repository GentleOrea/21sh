/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_completion_type.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 11:21:22 by tcharrie          #+#    #+#             */
/*   Updated: 2018/05/21 15:03:49 by tcharrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static int	ft_completion_type_isdot(char *str, int *val, int i, int max)
{
	val[10] = 0;
	val[11] = 0;
	while (str[i] && i < max && !val[11] && ft_isin(str[i], "'\"\\")
			&& (!val[10] || str[i] == val[10]))
	{
		val[11] = (str[i] == '\\');
		if (val[10])
			val[10] = 0;
		else
			val[10] = str[i];
		i++;
	}
	if (i >= max)
		return (0);
	if (ft_isin(str[i], "./"))
		return (COMPLETION_FILE);
	return (COMPLETION_COM);
}

static int	ft_completion_type_bq(char *str, int *val, int i)
{
	if (!i || (!val[10] && !val[11] && ft_isin(str[i], " \n<>&|;`")))
		return (0);
	while (i > val[5] && val[12] && (val[10] || val[11] ||
				!ft_isin(str[i], " \n<>&|;`")))
	{
		val[11] = ft_bl_active(str, i, val[10]);
		val[10] = (val[10] && str[i] == val[10] && !val[11]) ? (0) : (val[10]);
		val[12] = (str[i] == val[12] && !val[11] && !val[10]) ? (0) : (val[12]);
		i -= ft_lenchar_l(str, i);
	}
	val[9] = i;
	while (val[12] && val[9] > val[5] && (ft_isin(str[val[9]], " \n") ||
			(ft_isin(str[val[9]], "'\"") && str[val[9]] == str[val[9] - 1])))
		val[9] -= (1 + ft_isin(str[val[9]], "'\""));
	if (val[9] > val[5] && str[val[9]] != '`')
		return (COMPLETION_FILE);
	return (ft_completion_type_isdot(str, val, i + 1, val[0]));
}

/*
** À ce moment, on a j qui est le début du mot qui nous concerne
** et i qui est la première case à sa gauche
** L'objectif est de vérifier qu'on est bien bloqués à gauche avant d'appeler
** ft_completion_type_isdot()
*/

static int	ft_completion_type_nobq(char *str, int *val, int i, int j)
{
	printf("ft_completion_type_nobq avec %d|%d\n", i, j);
	if (i == j || j < 0 || i < 0)
		return (0);
	if (i == 0 && ft_isin(*str, " \n;&|") && str[1] == '.')
		return (COMPLETION_FILE);
	else if (i == 0)
		return (COMPLETION_COM);
	while (i > 0 && (ft_isin(str[i], " \n") || (ft_isin(str[i], "'\"") &&
			str[i] == str[i - 1])))
		i -= (1 + ft_isin(str[i], "'\""));
	if (i < 0)
		return (0);
	if (i > 0 && !ft_isin(str[i], "<>&|; \n"))
		return (COMPLETION_FILE);
	if (i == 0 && !ft_isin(str[i], " \n"))
		return (COMPLETION_FILE);
	return (ft_completion_type_isdot(str, val, j, val[0] - val[1]));
}

int			ft_completion_type(t_line *line, int *val)
{
	int		i;
	char	*str;

	if (!line || !line->line || !val || val[0] <= val[5])
		return (0);
	if (val[4] == 0)
		return (COMPLETION_FILE);
	str = &(line->line)[val[1]];
	i = val[0] - val[1] - ft_lenchar_l(str, val[0] - val[1]);
	val[12] = ft_separator_active(str, i, &val[10], &val[11]);
	printf("SEP : %d BL : %d BQ : %d\n", val[10], val[11], val[12]);
	if (val[12])
		return (ft_completion_type_bq(line->line, val, i));
	i = val[0] - val[1] - ft_completion_startpos(str, val[0] - val[1]);
	if (i == val[0] - val[1])
		return (0);
	if (i <= 0)
		return (ft_completion_type_isdot(str, val, 0, val[0] - val[1]));
	return (ft_completion_type_nobq(str, val,
		i - ft_lenchar_l(str, i), i));
}
