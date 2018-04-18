/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 16:22:30 by ygarrot           #+#    #+#             */
/*   Updated: 2018/04/18 11:32:19 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

/*
** Useless, odd try
*/

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

int		search_op(char *str, char *op)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		i += skip_comm(&str[i]);
		if (ft_strnstr(&str[i], op, ft_strlen(op)))
			return (i);
	}
	return (0);
}

/*
** Split la chaine avec comme splitchar ';' && '&'
*/

void	medium_split(t_comm *c, char *str, char *op)
{
	int		ind;

	while ((ind = search_op(str, op)))
	{
		c = push_front(c, ft_strndup(str, ++ind));
		str = &str[ind];
	}
	c = push_front(c, str);
	c->comm = str;
}

void	easy_split(t_comm *c, char *str, char *op)
{
	int		ind;

	while ((ind = search_op(str, op)))
	{
		c = push_front(c, ft_strndup(str, ++ind));
		str = &str[ind];
	}
	c = push_front(c, str);
	c->comm = str;
}

void	hard_split(t_comm *c, char *str)
{
	char	**tab;
	t_parser par;
	int		i;
	
	i = -1;
	if (count_comm(&par, str) < 0)
		exit(ft_printf("you fool\n"));
	mallcheck(tab = ft_strsplit_comm(str, ";"));
	while (tab[++i])
		medium_split(c, tab[i], "&");
	temp[0] = c;
	while (temp[0])
	{ 
	}
}

int main(int ac, char **av)
{
	t_comm *co = (t_comm*)ft_memalloc(sizeof(t_comm));

	(void)av;(void)ac;
	hard_split(co, av[1]);
	while (co)
	{
		ft_printf("%s\n", co->comm);
		co = co->next;
	}
}


