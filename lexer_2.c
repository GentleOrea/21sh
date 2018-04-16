/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 16:22:30 by ygarrot           #+#    #+#             */
/*   Updated: 2018/04/16 17:59:39 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

int		size_hard_split(char *str)
{
	int		i;
	char	q;

	i = 0;
	
	while (str[i] && !ft_isin(str[i], H_SEP))
	{
		if (ft_isin(str[++i], QUOTES) && (q = str[i] == '"' ? '"' : '\''))
			while (str[i] && str[++i] != q)
				;
	}
	if (str[i] == ';' || ft_strnstr(&str[i], ";;", 2))
		return (!ft_strnstr(&str[i], ";;", 2) ? 0 : -1);
	return (i || !str[i] ? i : -1);
}

/*
** Split la chaine avec comme splitchar ';' && '&'
*/

void	hard_split(t_comm *c, char *str)
{
	int		i;
	int		nrow;
	int		csize;
	t_parser par;

	i = 0;
	nrow = 0;
	if (count_comm(&par, str) < 0)
		exit(ft_printf("yoo fool\n"));
	while (str[i])
	{
		csize = size_hard_split(&str[i]); 
		mallcheck(c->comm = (char*)ft_memalloc((csize + str[csize] ? 0 : 1) * sizeof(char)));
		ft_memcpy(c->comm, &str[i], csize - 1);
		ft_printf("%d]%d]%s\n", i, csize, c->comm);
		i += csize;
		mallcheck(c->next = (t_comm*)ft_memalloc(sizeof(t_comm)));
		c = c->next;
	}
}
