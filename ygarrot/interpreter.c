/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compreter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 10:50:01 by ygarrot           #+#    #+#             */
/*   Updated: 2018/04/23 14:42:56 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

void	epur_tab(t_com *com, int len)
{
	int		i;
	t_tab	*to_del;
	t_tab	*list;

	i = -1;
	list = com->tab;
	ft_memdel((void**)&com->cli);
	mallcheck(com->cli = (char**)ft_memalloc((len  + 1) * sizeof(char*)));
	while (list)
	{
		com->cli[++i] = list->str;
		to_del = list;
		list = list->next;
		ft_memdel((void**)&to_del);
	}
	com->tab = NULL;
}

static void	add_comm(t_com *com, char *str)
{
	t_tab	*to_add;
	t_tab	*temp;
	
	mallcheck(to_add = (t_tab*)ft_memalloc(sizeof(t_tab)));
	to_add->str = str;
	temp = com->tab;
	if (!temp)
	{
		com->tab = to_add;
		return ;
	}
	while (temp->next)
		temp = temp->next;
	temp->next = to_add;
}

static void	add_redi(t_com *com, char **tab, int *i)
{
	t_redi	*redi;
	t_redi	*temp;
	int		len;

	mallcheck(redi = (t_redi*)ft_memalloc(sizeof(t_redi)));
	redi->fd[0] = ft_isdigit(**tab) ? ft_atoi(*tab) : -1;
	while (**tab && ft_isdigit(**tab))
		++*tab;
	redi->type = get_sep(*tab, REDI);
	len = ft_strlen(REDI[redi->type]);
	if (!(tab[0][len]) && ++*i)
		redi->path = ft_strdup(tab[1]);
	else
		redi->path = ft_strdup(&tab[0][len]);
	temp = com->redi;
	if (!temp)
	{
		com->redi = redi;
		return ;
	}
	while (temp->next)
		temp = temp->next;
	temp->next = redi;
}

void	split_co(t_shell *sh, t_parser *tmp)
{
	t_com	*com;
	int		i;

	mallcheck(com = (t_com*)ft_memalloc(sizeof(t_com)));
	sh->com = com;
	while (tmp)
	{
		if (tmp->next)
			mallcheck(com->next = (t_com*)ft_memalloc(sizeof(t_com)));
		com->cli = ft_strsplit_comm(tmp->comm, " ");
		i = -1;
		while (com->cli[++i])
		{
			ft_printf("%s\n", com->cli[i]);
			if (search_op(com->cli[i], REDI) >= 0)
				add_redi(com, &com->cli[i], &i);
			else if (++com->len)
				add_comm(com, com->cli[i]);
		
		}
		com->type = tmp->type;
		tmp = tmp->next;
		com = com->next;
	}
	sort_comm(sh, sh->com);
}
