/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_history_parser.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 12:02:43 by tcharrie          #+#    #+#             */
/*   Updated: 2018/04/24 12:42:34 by tcharrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/sh.h"

char	*ft_history_parser(char *str)
{
	char	*res;
	int		t[4];

	if (!(res = (char*)ft_memalloc(ft_strlen(str) + 1)))
		return (0);
	ft_bzero((void*)t, sizeof(t));
	while (str[t[0]])
	{
		if (!t[2] && !t[3] && str[t[0]] == '\\' && str[t[0] + 1] == '\n')
			t[0] += 2;
		else if (t[3] && str[t[0]] == '\n')
			t[0]++;
		else
		{
			t[2] = (!t[2] && t[3] != '"' && str[t[0]] == '\\');
			t[3] = ft_separator(str[t[0]], t[3], t[2]);
			res[t[1]++] = str[t[0]++];
		}
	}
	return (res);
}
