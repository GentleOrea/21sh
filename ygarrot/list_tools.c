/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 17:26:45 by ygarrot           #+#    #+#             */
/*   Updated: 2018/04/26 12:36:18 by ygarrot          ###   ########.fr       */
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

t_com	*shift_com(t_com *com, int fail)
{
	t_com *to_del;

	to_del = com;
	ft_free_dblechar_tab(com->cli);
	com = com->next;
	ft_memdel((void**)&to_del);
	while (com && (com->type && !(com->type & 32)
				&& !(com->type & (fail > 0 ? 2 : 1))))
	{
		to_del = com;
		epur_tb(com, com->len);
		com = com->next;
		ft_memdel((void**)&to_del);
	}
	return (com);
}
