/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 11:39:04 by ygarrot           #+#    #+#             */
/*   Updated: 2018/04/23 15:56:52 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

int		skip_comm(char *str)
{
	int		i;
	char	q;

	i = 0;
	if (!str)
		return (0);
	if (ft_isin(str[i], QUOTES) && (q = str[i++] == '"' ? '"' : '\''))
		while (str[i] && str[i++] != q)
			;
	while (str[i] == '\\')
		i += str[i + 1] ? 2 : 1;
	return (i);
}

int		get_sep(char *str, char **tab)
{
	int	i;

	i = -1;
	while (tab[++i] && ft_strncmp(str, tab[i], ft_strlen(tab[i])))
		;
	return (i);
}

/*
** strnstr pour un tableau passé en param
** renvoie la taille de la chaine si trouvée dans le tab sinon 0
*/

char		is_sep(char *str, t_parser *par, char **tab)
{
	int		i;
	int		len;

	i = -1;
	while (tab[++i] && !ft_strnstr(str, tab[i], len = ft_strlen(tab[i])))
		;
	tab[i] ? ft_strcpy(par->op, tab[i]) : 0;
	return (tab[i] ? len : 0);
}

/*
** recherche la premiere occurence d'une chaine du tableau donné en param
** dans la chaine donné en second param
*/

int		search_op(char *str, char **op)
{
	int	i;
	int	ind;
	int	tmp;

	i = 0;
	while (str[i])
	{
		ind = -1;
		while (op[++ind])
			if (!ft_strncmp(&str[i], op[ind] , ft_strlen(op[ind])))
				if (op[0][0] != '&' || !str[i]
|| (!ft_isin(str[i + 1], "<&") && (i <= 0 || !ft_isin(str[i - 1], "&>"))))
					return (i);
		i += ((tmp = skip_comm(&str[i])) ? tmp : 1);
	}
	return (-1);
}
