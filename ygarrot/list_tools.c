/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 17:26:45 by ygarrot           #+#    #+#             */
/*   Updated: 2018/04/17 18:47:45 by ygarrot          ###   ########.fr       */
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
