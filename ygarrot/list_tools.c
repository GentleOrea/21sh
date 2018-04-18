/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 17:26:45 by ygarrot           #+#    #+#             */
/*   Updated: 2018/04/18 17:20:27 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

t_comm	*push_front(t_comm *com, char *str)
{
	t_comm	*ret;
	t_comm	*begin;

	begin = com;
	if (!str)
		return (NULL);
	if (com && !com->comm && (com->comm = str))
		return (com);
	mallcheck(ret = (t_comm*)ft_memalloc(sizeof(t_comm)));
	ret->comm = str;
	if (!com)
		return (ret);
	while (com->next)
		com = com->next;
	com->next = ret;
	return (begin);
}

void	pop(t_comm *co)
{
	(co->next) ? co->next->prev = co->prev : 0;
	(co->prev) ? co->prev->next = co->prev : 0;
}

void	insert_co(t_comm *co, char *str, int type)
{
	t_comm *ins;

	if (!co)
		return ;
	mallcheck(ins = (t_comm*)ft_memalloc(sizeof(t_comm)));
	ins->comm = str;
	ins->type = type;
	co->next = ins;
}
