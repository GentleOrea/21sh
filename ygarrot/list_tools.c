/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 17:26:45 by ygarrot           #+#    #+#             */
/*   Updated: 2018/04/21 13:41:52 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

t_parser	*push_front(t_parser *com, char *str, int type)
{
	t_parser	*ret;
	t_parser	*begin;

	begin = com;
	if (!str)
		return (NULL);
	if (com && !com->comm)
	{
		com->comm = str;
		com->type = type;
		return (com);
	}
	mallcheck(ret = (t_parser*)ft_memalloc(sizeof(t_parser)));
	ret->comm = str;
	ret->type = type;
	if (!com)
		return (ret);
	while (com->next)
		com = com->next;
	com->next = ret;
	return (begin);
}
/*
void	pop(t_parser *co)
{
	(co->next) ? co->next->prev = co->prev : 0;
	(co->prev) ? co->prev->next = co->prev : 0;
}

void	insert_co(t_parser *co, char *str, int type)
{
	t_parser *ins;

	if (!co)
		return ;
	mallcheck(ins = (t_parser*)ft_memalloc(sizeof(t_parser)));
	ins->comm = str;
	ins->type = type;
	co->next = ins;
}*/
