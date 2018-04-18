/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_and_replace.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 11:55:23 by ygarrot           #+#    #+#             */
/*   Updated: 2018/04/18 15:37:08 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

/*
** Cherche un charactere dans une chaine et le remplace par un autre charactere
** Sauf si celui-ci n'existe pas, dans ces cas la le char sera vide;
** op : 1 pour skip les comments
*/

static char	*replace(char *str, char *rep, int op, int len)
{
	char	*ret;
	char	q;
	int		i;
	int		i2;

	i = -1;
	i2 = -1;
	if (!(ret = ft_strnew(len)))
		return (NULL);
	while (str[++i])
	{
		if (str[i] == rep[0])
			rep[1] ? ret[++i2] = rep[1] : 0;
		else
			ret[++i2] = str[i];
		if (op & 1 && (ft_isin(str[i], QUOTES) && (q = str[i] == '"' ? '"' : '\'')))
		{
			ret[++i2] = str[i];
			while (str[++i] && str[i] != q)
				ret[++i2] = str[i];
		}
	}
	return (ret);
}

char	*ft_find_and_replace(char *str, char *rep, int op)
{
	int		len;
	int		i;

	i = -1;
	len = ft_strlen(str);
	if (!str)
		return (NULL);
	while (str[++i])
	{
		!rep[1] && str[i++] == rep[0] ? len-- : 0;
		op & 1 ? i += skip_comm(&str[i]) : 0;
	}
	return (replace(str, rep, op, len));
}
