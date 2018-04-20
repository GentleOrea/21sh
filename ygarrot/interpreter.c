/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpreter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 10:50:01 by ygarrot           #+#    #+#             */
/*   Updated: 2018/04/20 18:45:38 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

void	epur_tab(t_inter *inte, int len)
{
	int		i;
	t_tab	*to_del;
	t_tab	*list;

	i = -1;
	list = inte->tab;
	ft_memdel((void**)&inte->cli);
	mallcheck(inte->cli = (char**)ft_memalloc((len  + 1) * sizeof(char*)));
	while (list)
	{
		inte->cli[++i] = list->str;
		to_del = list;
		list = list->next;
		ft_memdel((void**)&to_del);
	}
	inte->tab = NULL;
}

static void	add_comm(t_inter *inte, char *str)
{
	t_tab	*to_add;
	t_tab	*temp;
	
	mallcheck(to_add = (t_tab*)ft_memalloc(sizeof(t_tab)));
	to_add->str = str;
	temp = inte->tab;
	if (!temp)
	{
		inte->tab = to_add;
		return ;
	}
	while (temp->next)
		temp = temp->next;
	temp->next = to_add;
}

static void	add_redi(t_inter *inte, char **tab, int *i)
{
	t_redi	*redi;
	t_redi	*temp;
	int		len;

	mallcheck(redi = (t_redi*)ft_memalloc(sizeof(t_redi)));
	redi->n = ft_isdigit(**tab) ? ft_atoi(*tab) : -1;
	while (**tab && ft_isdigit(**tab))
		tab++;
	redi->type = get_sep(*tab, REDI);
	len = ft_strlen(REDI[redi->type]);
	if (!(tab[0][len]) && ++*i)
		redi->path = ft_strdup(tab[1]);
	else
		redi->path = ft_strdup(&*tab[len]);
	temp = inte->redi;
	if (!temp)
	{
		inte->redi = redi;
		return ;
	}
	while (temp->next)
		temp = temp->next;
	temp->next = redi;
}

void	split_co(t_shell *sh, t_comm *tmp)
{
	t_inter	*inte;
	int		i;

	while (tmp)
	{
		
		inte->cli = ft_strsplit_comm(tmp->comm, " ");
		i = -1;
		while (inte->cli[++i])
		{
			if (search_op(inte->cli[i], REDI) >= 0)
				add_redi(inte, &inte->cli[i], &i);
			else if (++inte->len)
				add_comm(inte, inte->cli[i]);
		}
		tmp = tmp->next;
	}
	sort_comm(sh, inte);
}
