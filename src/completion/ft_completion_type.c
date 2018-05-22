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

static int	ft_completion_type_combyfile(char *str, int *val, int i, int max)
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
	return (ft_completion_type_combyfile(str, val, i + 1, val[0]));
}

static int	ft_completion_type_nobq(char *str, int *val, int i, int j)
{
	if (j == 0 && ft_isin(*str, " \n;&|") && str[1] == '.')))
		return (COMPLETION_FILE);
	else if (j == 0)
		return (COMPLETION_COM);
	while (j > 0 && (ft_isin(str[j], " \n") || (ft_isin(str[j], "'\"") &&
			str[j] == str[j - 1] && !ft_bl_active(str, j - 1, 0))))
		j -= (1 + ft_isin(str[j], "'\""));
	if (j > 0 && !ft_isin(str[j], "<>'\""))
		return (COMPLETION_FILE);
	if (j == 0 && i > 0 && !ft_isin(str[j], " \n"))
		return (ft_isin(str[i], "./") ? COMPLETION_COM : COMPLETION_FILE);
	return (ft_completion_type_combyfile(str, val, i, val[0]));
}

int			ft_completion_type(t_line *line, int *val)
{
	int		i;
	char	*str;

	if (!line || !(str = line->line) || !val || val[0] <= val[5])
		return (0);
	if (val[4] == 0)
		return (COMPLETION_FILE);
	i = val[0] - ft_lenchar_l(str, val[0]);
	val[12] = ft_separator_active(line->line, i, &val[10], &val[11]);
	if (val[12])
		return (ft_completion_type_bq(line->line, val, i));
	while (i > val[5] && (val[10] || val[11] || !ft_isin(str[i], " \n<>&|`")))
	{
		val[11] = ft_bl_active(str, i, val[10]);
		ft_separator(str[i], &val[10], &val[11], 0);
		i -= ft_lenchar_l(str, i);
	}
	if (i > val[5] && i >= val[0] - ft_lenchar_l(str, val[0]))
		return (0);
	if (ft_isin(str[i], "&|;"))
		return (ft_completion_type_combyfile(line->line, val, i + 1, val[0]));
	if (!i || ft_isin(str[i], "<>`"))
		return (!i ? ft_completion_type_combyfile(str, val, 0, val[0]) :
				COMPLETION_FILE);
	return (ft_completion_type_nobq(str, val, i + 1, i));
}
